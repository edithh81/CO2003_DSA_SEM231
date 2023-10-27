#include "main.h"
class resQueue;
class imp_res;
class Ele;
int max_idx = 1;
const int MAX_INT = 1e6 + 5;
// -----------------------------------------------------
class imp_res : public Restaurant
{
private:
	class Ele
	{
	public:
		customer* data;
		Ele* next;
		Ele* prev;
		int idx;
		Ele(customer* c)
		{
			this->data = c;
			this->next = nullptr;
			this->prev = nullptr;
			this->idx = 0;
		}
		Ele(const Ele* c) {
			this->data = c->data;
			this->next = c->next;
			this->prev = c->prev;
			this->idx = c->idx;
		}
		void setIdx(const int& x) {
			this->idx = x;
		}
		Ele* operator+(int n) {
			Ele* p(this);
			while (n-- && p) {
				p = p->next;
			}
			return p;
		}
		Ele* operator-(int n) {
			Ele* p(this);
			while (n-- && p) {
				p = p->prev;
			}
			return p;
		}
	};
	class resQueue
	{
	public:
		Ele* Head;
		Ele* Tail;
		int nCurCus;
		int nOnryo;
		int nMagician;
		bool isPurpled;
	public:
		resQueue()
		{
			this->Head = nullptr;
			this->Tail = nullptr;
			nCurCus = 0;
			nOnryo = 0;
			nMagician = 0;
			isPurpled = false;
		}
		~resQueue() {
			Ele* p = Head;
			while (p) {
				Ele* temp = p;
				p = p->next;
				delete temp;
			}
		}
		void Push(customer*& c) {
			if (c->energy < 0)	++nOnryo;
			else				++nMagician;
			++this->nCurCus;
			if (this->Head == nullptr)
			{
				Head = new Ele(c);
				Tail = Head;
				Head->setIdx(max_idx);
				Tail->setIdx(max_idx);
			}
			else {
				Tail->next = new Ele(c);
				Tail->next->setIdx(max_idx);
				Tail->next->prev = Tail;
				Tail = Tail->next;
			}
			++max_idx;
		}
		void Pop() {
			if (this->nCurCus == 0) 	return;
			// Case current Queue
			if (this->Head->data->energy < 0)	--nOnryo;
			else								--nMagician;
			--nCurCus;
			Ele* temp = Head;
			Head = Head->next;
			if (nCurCus == 0) {
				Head = Tail = nullptr;
				// isPurpled = false;
			}
			else Head->prev = nullptr;
			delete temp;
		}
		int getIdxFront() {
			return Head->idx;
		}
		customer* Front() { return this->Head->data; }
		customer* Back() {
			return Tail->data;
		}
		void setidxBack(const int& idx) {
			this->Tail->idx = idx;
		}
		void resetIdx() {
			Ele* p = Head;
			for (int i = 0; i < nCurCus && p; i++) {
				p->idx = i;
				p = p->next;
			}
		}
		Ele* maxAbsEnergy(int& idx) {
			if (this->Head == nullptr)	return nullptr;
			Ele* p = this->Head->next;
			int maxEne = abs(this->Head->data->energy);
			Ele* ans = this->Head;
			int i = 1;
			while (p) {
				if (maxEne <= abs(p->data->energy)) {
					maxEne = abs(p->data->energy);
					ans = p;
					idx = i;
				}
				++i;
				p = p->next;
			}
			return ans;
		}
		void Swap(Ele* a, Ele* b) {
			customer* temp = a->data;
			a->data = b->data;
			b->data = temp;
			int tmp = a->idx;
			a->idx = b->idx;
			b->idx = tmp;
		}
		void clear() {
			if (empty())	return;
			while (!empty())
				Pop();
		}
		void inssort(Ele* start, const int& incre, const int& n, int& step) {
			for (int i = incre; i < n; i += incre) {
				for (int j = i; (j >= incre); j -= incre) {
					Ele* temp1 = start->operator+(j);
					Ele* temp2 = temp1->operator-(incre);
					if ((abs(temp1->data->energy) == abs(temp2->data->energy) && temp1->idx < temp2->idx) || abs(temp1->data->energy) > abs(temp2->data->energy)) {
						Swap(temp1, temp2);
						++step;
					}
				}
			}
		}
		void ShellSort(int& step) {
			if (this->nCurCus == 1)	return;
			int idx = 0;
			Ele* maxEnergy = this->maxAbsEnergy(idx);
			int nEl = idx + 1;
			for (int i = nEl / 2; i > 2; i /= 2) {
				for (int j = 0; j < i; j++) { // for each sublist
					Ele* p = this->Head;
					for (int k = 0; k < j; k++) {
						p = p->next;
					}
					inssort(p, i, nEl - j, step);// sort each sublist
				}
			}
			Ele* p = this->Head;
			inssort(p, 1, nEl, step);
		}
		bool empty() { return nCurCus == 0; }
		bool isFull() { return nCurCus == MAXSIZE; }
		int getSize() { return nCurCus; }
		bool checkDuplicateName(const string& name)
		{
			if (this->nCurCus == 0)	return false;
			Ele* tmp = this->Head;
			while (tmp)
			{
				if (tmp->data->name == name)
					return true;
				tmp = tmp->next;
			}
			return false;
		}
		void Light()
		{
			if (this->Head == nullptr)
				return;
			Ele* temp = this->Head;
			for (int i = 0; i < nCurCus && temp; i++) {
				temp->data->print();
				temp = temp->next;
			}
		}
		int CalEnergyofOnryo()
		{
			if (nCurCus == 0 || nOnryo == 0)	return 0;
			int res = 0;
			Ele* p = this->Head;
			for (int i = 0; i < this->nCurCus && p; i++) {
				if (p->data->energy < 0)	res += p->data->energy;
				p = p->next;
			}
			return res;
		}
		int CalEnergyofMagician()
		{
			if (nCurCus == 0 || nMagician == 0)	return 0;
			int res = 0;
			Ele* p = this->Head;
			for (int i = 0; i < this->nCurCus && p; i++) {
				if (p->data->energy > 0) 	res += p->data->energy;
				p = p->next;
			}
			return res;
		}
		void LightDomain() {
			if (this->getSize() == 0)	return;
			Ele* temp = this->Tail;
			for (int i = 0; i < this->getSize(); i++) {
				customer* t = temp->data;
				temp->data->print();
				delete t;
				temp = temp->prev;
			}
		}
		void inssortafterPurple(Ele* start, const int& incre, const int& n) {
			for (int i = incre; i < n; i += incre) {
				for (int j = i; j >= incre; j -= incre) {
					Ele* a = start->operator+(j);
					Ele* b = a->operator-(incre);
					if (a->idx < b->idx)
						Swap(a, b);
				}
			}
		}
		void afterPurple() {
			int sz = nCurCus;
			for (int i = sz / 2; i > 2; i /= 2) {
				for (int j = 0; j < i; j++) {
					Ele* p = this->Head;
					for (int k = 0; k < j; k++)	 p = p->next;
					inssortafterPurple(p, i, sz - j);
				}
			}
			Ele* p = this->Head;
			inssortafterPurple(p, 1, sz);
		}
		void afterExecuted() {
			Ele* p = Head;
			for (int i = 0; i < nCurCus && p; i++) {
				customer* t = p->data;
				delete t;
				p = p->next;
			}
		}
	};
	customer* Cur;
	resQueue* CurQ;
	resQueue* WaitQ;
public:
	friend class resQueue;
	imp_res() {
		this->Cur = nullptr;
		this->CurQ = new resQueue();
		this->WaitQ = new resQueue();
	}
	~imp_res() {
		CurQ->afterExecuted();
		delete CurQ;
		WaitQ->afterExecuted();
		delete WaitQ;
	}
	customer* maxDifELe(const int& energy) {
		int res = abs(energy - this->Cur->energy);
		customer* temp = this->Cur->next;
		customer* ans = this->Cur;
		for (int i = 1; i < this->CurQ->getSize() && temp; i++)
		{
			if (res < abs(energy - temp->energy))
			{
				ans = temp;
				res = abs(energy - temp->energy);
			}
			temp = temp->next;
		}
		return ans;
	}
	void changeList(customer*& a, customer*& b) {
		customer* prevA = a->prev;
		customer* nextB = b->next;
		customer* nextA = a->next;
		customer* prevB = b->prev;
		// case a->prev = b->next
		if (prevA == b) {
			a->prev = b->prev;
			b->next = a->next;
			a->next->prev = b;
			b->prev->next = a;
			a->next = b;
			b->prev = a;
		}
		else if (nextA == b) {
			a->next = b->next;
			b->prev = a->prev;
			a->prev->next = b;
			b->next->prev = a;
			a->prev = b;
			b->next = a;
		}
		else {
			// set b
			prevA->next = b;
			b->prev = prevA;
			b->next = nextA;
			nextA->prev = b;
			// set a
			prevB->next = a;
			a->prev = prevB;
			a->next = nextB;
			nextB->prev = a;
		}
	}
	void printLongestSubSequence(customer* start, int len) {
		customer* minEl = start;
		customer* p = start;
		int minVal = start->energy;
		int numBackEL = len;
		for (int i = 0; i < len; i++) {
			if (minVal > p->energy) {
				minVal = p->energy;
				minEl = p;
				numBackEL = len - i;
			}
			p = p->next;
		}
		for (int i = 0; i < numBackEL; i++) {
			minEl->print();
			minEl = minEl->next;
		}
		for (int i = 0; i < len - numBackEL; i++) {
			start->print();
			start = start->next;
		}
	}
	customer* nextsameSignClockWise(customer* c) {
		customer* p = c->next;
		for (int i = 0; i < this->CurQ->getSize(); i++) {
			if (p->energy * c->energy > 0)
				return p;
			p = p->next;
		}
		return nullptr;
	}
	customer* nextsameSignCounterClockWise(customer* c) {
		customer* p = c->prev;
		for (int i = 0; i < this->CurQ->getSize(); i++) {
			if (p->energy * c->energy > 0)
				return p;
			p = p->prev;
		}
		return nullptr;
	}
	void RED(string name, int energy) {
		// not accept energy = 0
		// check duplicate name
		if (energy == 0 || CurQ->checkDuplicateName(name) || WaitQ->checkDuplicateName(name)) return;
		customer* newCus = new customer(name, energy, nullptr, nullptr);
		// Restaurant is full
		if (CurQ->isFull())
		{
			if (WaitQ->isFull()) {
				delete newCus;
				return;
			}
			WaitQ->Push(newCus);
			return;
		}

		// curQ empty
		if (CurQ->empty())
		{
			CurQ->Push(newCus);
			Cur = newCus;
			return;
		}
		// curQ not empty
		// cout << "<MAXSIZE/2" << endl;
		if (CurQ->getSize() < MAXSIZE / 2)
		{
			if (energy >= this->Cur->energy)
			{
				customer* nCur = this->Cur->next;
				this->Cur->next = newCus;
				newCus->prev = this->Cur;
				if (nCur)
				{
					newCus->next = nCur;
					nCur->prev = newCus;
				}
				else
				{
					this->Cur->prev = newCus;
					newCus->next = this->Cur;
				}
				this->Cur = newCus;
			}
			else
			{
				customer* pCur = this->Cur->prev;
				this->Cur->prev = newCus;
				newCus->next = this->Cur;
				if (pCur)
				{
					newCus->prev = pCur;
					pCur->next = newCus;
				}
				else
				{
					this->Cur->next = newCus;
					newCus->prev = this->Cur;
				}
				this->Cur = newCus;
			}
			this->CurQ->Push(newCus);
			return;
		}
		// >= MAXSIZE/2
		customer* Pos = this->maxDifELe(energy);
		if (energy - Pos->energy > 0)
		{
			customer* temp = Pos->next;
			Pos->next = newCus;
			newCus->prev = Pos;
			if (temp)
			{
				newCus->next = temp;
				temp->prev = newCus;
			}
			else {
				Pos->prev = newCus;
				newCus->next = Pos;
			}
			this->Cur = newCus;
		}
		else
		{
			customer* temp = Pos->prev;
			Pos->prev = newCus;
			newCus->next = Pos;
			if (temp)
			{
				newCus->prev = temp;
				temp->next = newCus;
			}
			else {
				Pos->next = newCus;
				newCus->prev = Pos;
			}
			this->Cur = newCus;
		}
		this->CurQ->Push(newCus);
	}
	void BLUE(int num) {
		// num >= MAXSIZE
		if (num == 0)	return;
		if ((num >= MAXSIZE || num >= this->CurQ->getSize()) && this->CurQ->getSize())
		{
			while (!CurQ->empty()) {
				customer* p = this->CurQ->Front();
				CurQ->Pop();
				delete p;
			}
		}
		else if (this->CurQ->getSize())
		{
			// Pop element
			while (num--)
			{
				customer* temp = this->CurQ->Front();
				// cout << temp->energy << endl;
				if (temp->energy > 0)
					this->Cur = temp->next;
				else
					this->Cur = temp->prev;
				customer* prevTemp = temp->prev;
				customer* nextTemp = temp->next;
				prevTemp->next = nextTemp;
				nextTemp->prev = prevTemp;
				CurQ->Pop();
				delete temp;
			}
		}
		int remainCus = MAXSIZE - CurQ->getSize();
		resQueue* readytoGetIn = new resQueue();
		while (!WaitQ->empty() && remainCus--) {
			customer* t = WaitQ->Front();
			int fIdx = WaitQ->getIdxFront();
			WaitQ->Pop();
			readytoGetIn->Push(t);
			readytoGetIn->setidxBack(fIdx);
		}
		while (!readytoGetIn->empty()) {
			customer* t = readytoGetIn->Front();
			int fIdx = readytoGetIn->getIdxFront();
			readytoGetIn->Pop();
			if (CurQ->empty())	Cur = t;
			else if (CurQ->getSize() < MAXSIZE / 2) {
				if (t->energy >= Cur->energy) {
					customer* nCur = Cur->next;
					Cur->next = t;
					t->prev = Cur;
					if (nCur) {
						t->next = nCur;
						nCur->prev = t;
					}
					else {
						Cur->prev = t;
						t->next = Cur;
					}
				}
				else {
					customer* pCur = Cur->prev;
					Cur->prev = t;
					t->next = Cur;
					if (pCur) {
						t->prev = pCur;
						pCur->next = t;
					}
					else {
						Cur->next = t;
						t->prev = Cur;
					}
				}
			}
			else if (CurQ->getSize() >= MAXSIZE / 2) {
				customer* Pos = maxDifELe(t->energy);
				if (t->energy - Pos->energy > 0) {
					customer* temp = Pos->next;
					Pos->next = t;
					t->prev = Pos;
					if (temp) {
						t->next = temp;
						temp->prev = t;
					}
					else {
						Pos->prev = t;
						t->next = Pos;
					}
				}
				else {
					customer* temp = Pos->prev;
					Pos->prev = t;
					t->next = Pos;
					if (temp)
					{
						t->prev = temp;
						temp->next = t;
					}
					else {
						Pos->next = t;
						t->prev = Pos;
					}
				}
			}
			Cur = t;
			CurQ->Push(t);
			CurQ->setidxBack(fIdx);
		}
		delete readytoGetIn;
		CurQ->afterPurple();
	}
	void PURPLE() {
		if (this->WaitQ->empty())	return;
		// variable to count num of swap of shellsort
		// max abs energy customer 
		int step = 0;
		this->WaitQ->ShellSort(step);
		if (step) WaitQ->isPurpled = true;
		// cout << step << endl;
		this->BLUE(step % MAXSIZE);
	};
	void REVERSAL() {
		if (this->CurQ->empty() || this->CurQ->getSize() == 1)
			return;
		// cout << "REVERSAL" << endl;
		int nOr = this->CurQ->nOnryo;
		int nMa = this->CurQ->nMagician;
		// cout << "nOr " <<  nOr << " nMa " << nMa << endl;
		// push positive energy and negative energy to queue
		resQueue* MaQ = new resQueue();
		resQueue* OrQ = new resQueue();
		customer* p = this->Cur;
		for (int i = 0; i < this->CurQ->getSize(); i++) {
			if (p->energy > 0)	MaQ->Push(p);
			else				OrQ->Push(p);
			p = p->prev;
		}
		// MaQ->Light();
		//reverse positive energy
		if (MaQ->getSize() > 2 || (OrQ->getSize() > 0 && MaQ->getSize() == 2) || (OrQ->getSize() == MaQ->getSize() && MaQ->getSize() == 2)) {
			customer* a = MaQ->Front();
			customer* b = MaQ->Back();
			for (int i = 0; i < nMa / 2; i++) {
				changeList(a, b);
				customer* temp = a;
				a = b;
				b = temp;
				a = nextsameSignCounterClockWise(a);
				b = nextsameSignClockWise(b);
			}
		}
		//reverse negative energy
		// OrQ->Light();
		if (OrQ->getSize() > 2 || (OrQ->getSize() == 2 && MaQ->getSize() > 0) || (OrQ->getSize() == MaQ->getSize() && MaQ->getSize() == 2)) {
			customer* c = OrQ->Front();
			customer* d = OrQ->Back();
			for (int i = 0; i < nOr / 2; i++) {
				changeList(c, d);
				customer* temp = c;
				c = d;
				d = temp;
				c = nextsameSignCounterClockWise(c);
				d = nextsameSignClockWise(d);
			}
		}
		delete OrQ;
		delete MaQ;
	};
	void UNLIMITED_VOID() {
		// Case size < 4
		if (this->CurQ->getSize() < 4)	return;
		// the remain case (brute force)
		customer* startList = this->Cur;
		int resLength = 4;
		// variables to traverse
		int minSum = MAX_INT;
		customer* pTravel = this->Cur;
		// get the min sum with each window size
		for (int i = 0; i < CurQ->getSize(); i++) {
			customer* pL = pTravel;
			int traverseMinSum = 0;
			for (int j = 1; j <= 4; j++) {
				traverseMinSum += pL->energy;
				pL = pL->next;
			}
			if (minSum > traverseMinSum) {
				startList = pTravel;
				resLength = 4;
				minSum = traverseMinSum;
			}
			else if (minSum == traverseMinSum && resLength == 4) {
				startList = pTravel;
				resLength = 4;
				minSum = traverseMinSum;
			}
			for (int j = 5; j <= CurQ->getSize(); j++) {
				traverseMinSum += pL->energy;
				if (traverseMinSum < minSum) {
					resLength = j;
					startList = pTravel;
					minSum = traverseMinSum;
				}
				else if (traverseMinSum == minSum && j >= resLength) {
					resLength = j;
					startList = pTravel;
					minSum = traverseMinSum;
				}
				pL = pL->next;
			}
			pTravel = pTravel->next;
		}
		this->printLongestSubSequence(startList, resLength);
	};
	resQueue* SackOnryo() {
		resQueue* Sacked = new resQueue();
		Ele* p = CurQ->Head;
		while (p)
		{
			if (p->data->energy < 0)
			{
				customer* e = p->data;
				Sacked->Push(e);
				Sacked->setidxBack(p->idx);
				customer* preve = e->prev;
				customer* nexte = e->next;
				if (preve) {
					this->Cur = preve;
					preve->next = nexte;
				}
				if (nexte) nexte->prev = preve;
				Ele* prevP = p->prev;
				Ele* nextP = p->next;
				if (prevP)
					prevP->next = nextP;
				else CurQ->Head = nextP;
				if (nextP)
					nextP->prev = prevP;
				else CurQ->Tail = prevP;
				delete p;
				p = nextP;
				--CurQ->nCurCus;
				--CurQ->nOnryo;
			}
			else p = p->next;
		}
		return Sacked;
	};
	resQueue* SackWaitOnryo() {
		resQueue* Sacked = new resQueue();
		Ele* p = WaitQ->Head;
		while (p)
		{
			if (p->data->energy < 0)
			{
				customer* e = p->data;
				Sacked->Push(e);
				Sacked->setidxBack(p->idx);
				Ele* prevP = p->prev;
				Ele* nextP = p->next;
				if (prevP)
					prevP->next = nextP;
				else WaitQ->Head = nextP;
				if (nextP)
					nextP->prev = prevP;
				else WaitQ->Tail = prevP;
				delete p;
				p = nextP;
				--WaitQ->nCurCus;
				--WaitQ->nOnryo;
			}
			else p = p->next;
		}
		return Sacked;
	};
	resQueue* SackMagician() {
		resQueue* Sacked = new resQueue();
		Ele* p = CurQ->Head;
		while (p)
		{
			if (p->data->energy > 0)
			{
				customer* e = p->data;
				Sacked->Push(e);
				Sacked->setidxBack(p->idx);
				customer* preve = e->prev;
				customer* nexte = e->next;
				if (preve) preve->next = nexte;
				if (nexte) {
					this->Cur = nexte;
					nexte->prev = preve;
				}
				Ele* prevP = p->prev;
				Ele* nextP = p->next;
				if (prevP)
					prevP->next = nextP;
				else CurQ->Head = nextP;
				if (nextP)
					nextP->prev = prevP;
				else CurQ->Tail = prevP;
				delete p;
				p = nextP;
				--CurQ->nCurCus;
				--CurQ->nMagician;
			}
			else p = p->next;
		}
		return Sacked;
	};
	resQueue* SackWaitMagician() {
		resQueue* Sacked = new resQueue();
		Ele* p = WaitQ->Head;
		while (p)
		{
			if (p->data->energy > 0)
			{
				customer* e = p->data;
				Sacked->Push(e);
				Sacked->setidxBack(p->idx);
				Ele* prevP = p->prev;
				Ele* nextP = p->next;
				if (prevP)
					prevP->next = nextP;
				else WaitQ->Head = nextP;
				if (nextP)
					nextP->prev = prevP;
				else WaitQ->Tail = prevP;
				delete p;
				p = nextP;
				--WaitQ->nCurCus;
				--WaitQ->nMagician;
			}
			else p = p->next;
		}
		return Sacked;
	};
	void DOMAIN_EXPANSION() {
		// Calc energy
		int sumEnergyofOnryo = CurQ->CalEnergyofOnryo() + WaitQ->CalEnergyofOnryo();
		int sumEnergyofMagician = CurQ->CalEnergyofMagician() + WaitQ->CalEnergyofMagician();
		// Process
		if (sumEnergyofMagician == 0 || sumEnergyofOnryo == 0)	return;
		if (sumEnergyofMagician >= abs(sumEnergyofOnryo))
		{
			// Sack Onryon
			resQueue* curOnryo = this->SackOnryo();
			resQueue* waitOnryo = this->SackWaitOnryo();
			// Has been sorted yet
			if (waitOnryo->getSize())
				waitOnryo->afterPurple();
			if (curOnryo->getSize())
				curOnryo->afterPurple();
			if (WaitQ->isPurpled) {
				resQueue* ans = new resQueue();
				while (!waitOnryo->empty() && !curOnryo->empty()) {
					if (curOnryo->getIdxFront() < waitOnryo->getIdxFront()) {
						customer* t = curOnryo->Front();
						ans->Push(t);
						ans->setidxBack(curOnryo->getIdxFront());
						curOnryo->Pop();
					}
					else {
						customer* t = waitOnryo->Front();
						ans->Push(t);
						ans->setidxBack(waitOnryo->getIdxFront());
						waitOnryo->Pop();
					}
				}
				while (!waitOnryo->empty()) {
					customer* t = waitOnryo->Front();
					ans->Push(t);
					ans->setidxBack(waitOnryo->getIdxFront());
					waitOnryo->Pop();
				}
				while (!curOnryo->empty()) {
					customer* t = curOnryo->Front();
					ans->Push(t);
					ans->setidxBack(curOnryo->getIdxFront());
					curOnryo->Pop();

				}
				ans->LightDomain();
				delete ans;
			}
			else {
				waitOnryo->LightDomain();
				curOnryo->LightDomain();
			}
			delete waitOnryo;
			delete curOnryo;
		}
		else
		{
			// Sack Magician
			resQueue* curMagician = this->SackMagician();
			resQueue* waitMagician = this->SackWaitMagician();
			if (waitMagician->getSize())
				waitMagician->afterPurple();
			if (curMagician->getSize())
				curMagician->afterPurple();
			if (WaitQ->isPurpled) {
				resQueue* ans = new resQueue();
				while (!waitMagician->empty() && !curMagician->empty()) {
					if (curMagician->getIdxFront() < waitMagician->getIdxFront()) {
						customer* t = curMagician->Front();
						ans->Push(t);
						ans->setidxBack(curMagician->getIdxFront());
						curMagician->Pop();
					}
					else {
						customer* t = waitMagician->Front();
						ans->Push(t);
						ans->setidxBack(waitMagician->getIdxFront());
						waitMagician->Pop();
					}
				}
				while (!waitMagician->empty()) {
					customer* t = waitMagician->Front();
					ans->Push(t);
					ans->setidxBack(waitMagician->getIdxFront());
					waitMagician->Pop();
				}
				while (!curMagician->empty()) {
					customer* t = curMagician->Front();
					ans->Push(t);
					ans->setidxBack(curMagician->getIdxFront());
					curMagician->Pop();

				}
				ans->LightDomain();
				delete ans;
			}
			else {
				waitMagician->LightDomain();
				curMagician->LightDomain();
			}
			delete curMagician;
			delete waitMagician;
		}
		int remainCus = MAXSIZE - CurQ->getSize();
		resQueue* readytoGetIn = new resQueue();
		while (!WaitQ->empty() && remainCus--) {
			customer* t = WaitQ->Front();
			int fIdx = WaitQ->getIdxFront();
			WaitQ->Pop();
			readytoGetIn->Push(t);
			readytoGetIn->setidxBack(fIdx);
		}
		while (!readytoGetIn->empty()) {
			customer* t = readytoGetIn->Front();
			int fIdx = readytoGetIn->getIdxFront();
			readytoGetIn->Pop();
			if (CurQ->empty())
				Cur = t;
			else if (CurQ->getSize() < MAXSIZE / 2) {
				if (t->energy >= Cur->energy) {
					customer* nCur = Cur->next;
					Cur->next = t;
					t->prev = Cur;
					if (nCur) {
						t->next = nCur;
						nCur->prev = t;
					}
					else {
						Cur->prev = t;
						t->next = Cur;
					}
				}
				else {
					customer* pCur = Cur->prev;
					Cur->prev = t;
					t->next = Cur;
					if (pCur) {
						t->prev = pCur;
						pCur->next = t;
					}
					else {
						Cur->next = t;
						t->prev = Cur;
					}
				}
			}
			else if (CurQ->getSize() >= MAXSIZE / 2) {
				customer* Pos = this->maxDifELe(t->energy);
				if (t->energy - Pos->energy > 0) {
					customer* temp = Pos->next;
					Pos->next = t;
					t->prev = Pos;
					if (temp) {
						t->next = temp;
						temp->prev = t;
					}
					else {
						Pos->prev = t;
						t->next = Pos;
					}
				}
				else {
					customer* temp = Pos->prev;
					Pos->prev = t;
					t->next = Pos;
					if (temp)
					{
						t->prev = temp;
						temp->next = t;
					}
					else {
						Pos->next = t;
						t->prev = Pos;
					}
				}
			}
			Cur = t;
			CurQ->Push(t);
			CurQ->setidxBack(fIdx);
		}
		delete readytoGetIn;
		CurQ->afterPurple();
	};
	void LIGHT(int num) {
		if (num == 0) {
			this->WaitQ->Light();
			return;
		}
		if (this->CurQ->getSize() == 0)	return;
		customer* temp = this->Cur;
		for (int i = 0; i < this->CurQ->getSize() && temp; i++) {
			temp->print();
			temp = ((num > 0) ? temp->next : temp->prev);
		}
	}
};
