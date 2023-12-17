#include "main.h"
// declare class
class HuffTree;
class HuffNode;
class LeafNode;
class IntNode;
class Heap;
class BSTree;
// variable or some define to make code cleaner
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define pci pair<char, int> 
#define castInt(X) dynamic_cast<IntNode *>(X)
#define castLeaf(X) dynamic_cast<LeafNode *>(X)
#define ll long long
map<char, pii> m;
int MAXSIZE;
map<int, BSTree *> GojoRes;
map<int, queue<int>> GojoTime;
Heap *SukunaRes;
HuffTree *latestHuffTree = nullptr;

// class to use in assignment
class Heap{
	public:
		vector<pair<int, vector<pair<int,int>>>> elements;
		int recentlyUsed_idx;
	public:
		Heap(){
			elements.resize(0);
			recentlyUsed_idx = 0;
		}
		~Heap(){ elements.resize(0); elements.shrink_to_fit();}
		void push(const int &ID, const int &res){
			for (int i=0; i<(int)elements.size(); i++){
				if (elements[i].second.front().first == ID ){
					elements[i].second.push_back({ID, res});
					elements[i].first = recentlyUsed_idx++;
					reHeapDown(i);
					return;
				}
			}
			elements.push_back({recentlyUsed_idx++, {{ID,res}}});
			reHeapUp((int)elements.size()-1);
		}
		void remove(const int &ID){
			int idx = 0;
			for (auto &it : elements){
				if (it.second.front().first == ID){
					elements[idx] = elements[(int)elements.size() - 1];
					elements.pop_back();
					if (idx == (int)elements.size()) return;
					reHeapDown(idx);
					reHeapUp(idx);
					return;
				}
				++idx;
			}
		}
		void Keiteken(int ID, const int &num){
			int count = 0;
			for (auto &it: elements){
				if (it.second.front().first == ID){
					for (int i=0; i<num; i++)
						it.second.erase(it.second.begin());
					it.first = recentlyUsed_idx++;
					reHeapUp(count);
					reHeapDown(count);
					return;
				}
				++count;
			}
		}
		void reHeapUp(int idx){
			while (idx){
				int pIdx = (idx-1) >> 1;
				if ((int)elements[idx].second.size() > (int)elements[pIdx].second.size() || ((int)elements[idx].second.size() == (int)elements[pIdx].second.size() && (int)elements[idx].first > (int)elements[pIdx].first)) return;
				auto temp (move(elements[idx]));
				elements[idx] = move(elements[pIdx]);
				elements[pIdx] = move(temp);
				idx = pIdx;
			}
		}
		void reHeapDown(int idx){
			while (idx < (int)elements.size()){
				int cIdx = 2*idx+1;
				if (cIdx >= (int)elements.size())	return;
				if (cIdx + 1 < (int)elements.size() && (elements[cIdx+1].second.size() < elements[cIdx].second.size() || (elements[cIdx+1].second.size() == elements[cIdx].second.size() && elements[cIdx+1].first < elements[cIdx].first))) cIdx++;
				if (elements[idx].second.size() < elements[cIdx].second.size() || (elements[idx].second.size() == elements[cIdx].second.size() && elements[idx].first < elements[cIdx].first))	return;
				auto temp (move(elements[idx]));
				elements[idx] = move(elements[cIdx]);
				elements[cIdx] = move(temp);
				idx = cIdx;
			}
		}
		void partial_CLEAVE(int idx, const int &num){
			if (idx >= (int)elements.size())	return;
			// cout << idx << endl;
			int temp = min(num, (int)SukunaRes->elements[idx].second.size());
			// cout << "num of cus: " << (int)SukunaRes->elements[idx].second.size() << " of zone " << (int)elements[idx].second.front().first << " in Sukuna Res" << endl;
			int j = elements[idx].second.size() - 1;
			for (int k = 0; k < temp; k++){
				cout << elements[idx].second[j].first << '-' << elements[idx].second[j].second << endl;
				--j;
			}
			partial_CLEAVE(2*idx+1, num);
			partial_CLEAVE(2*idx+2, num);
		}
};
class HuffNode {
public:
	virtual ~HuffNode(){}
    virtual int weight() = 0;
    virtual bool isLeaf() = 0;
	virtual void setWeight(const int &c) {};
};
// leaf node
class LeafNode: public HuffNode{
private:
    char key; // value
    int wgt; // weight
public:
    LeafNode(const char& val, int freq) { key = val; wgt = freq; };
	~LeafNode(){}
    int weight() { return wgt; }
    char val() { return key; }
    bool isLeaf() { return true; }
};    
class IntNode :public HuffNode {
private:
    HuffNode* left;
    HuffNode* right;
    int wgt;
public:
    IntNode(HuffNode* l, HuffNode* r) { wgt = l->weight() + r->weight(); left = l; right = r; };
	~IntNode(){}
	int weight() { return wgt; }
	void setWeight(const int &w){wgt = w;}
    bool isLeaf() { return false; }
    HuffNode* leftChild() const{ return left; }
    HuffNode* rightChild() const{ return right; }
    void setLeft(HuffNode* b) { left = (HuffNode*) b; }
    void setRight(HuffNode* b) { right = (HuffNode*) b; }
    HuffNode *getL(){return this->left;}
    HuffNode *getR(){return this->right;}
	HuffNode *&balanceLeft(){return this->left;}
    HuffNode *&balanceRight(){return this->right;}
};
class HuffTree {
private:
    HuffNode* root;
	int ord;
	HuffNode *rotateLeft(HuffNode *root){
		HuffNode *temp = castInt(root)->getR();
		castInt(root)->setRight(castInt(temp)->getL());
		castInt(temp)->setLeft(root);
		root = temp;
		return root;	
	}
	HuffNode *rotateRight(HuffNode *root){
		HuffNode *temp = castInt(root)->getL();
		castInt(root)->setLeft(castInt(temp)->getR());
		castInt(temp)->setRight(root);
		root = temp;
		return root;
	}
	int getBalance(HuffNode *root){
		if (root->isLeaf())	return 0;
		int leftBalance = getHeight(castInt(root)->getL());
		int rightBalance = getHeight(castInt(root)->getR());
		return leftBalance - rightBalance;
	}
	int getHeight(HuffNode *root){
		if (root->isLeaf())	return 0;
		int leftHeight = getHeight(castInt(root)->getL());
		int rightHeight = getHeight(castInt(root)->getR());
		return max(leftHeight, rightHeight) + 1;
	}
	void balanceTree(HuffNode *&root, int &count){
		if (root->isLeaf())	return;
		if (count == 3)	return;
		int bfTree = getBalance(root); // get balance factor to decide which case
		// cout << "bf of tree : " << bfTree << endl;
		if (bfTree == 0 || abs(bfTree) == 1) return; // tree has been balanced yet
		if (bfTree > 1){ // left higher
			int bfTreeLeft = getBalance(castInt(root)->getL()); // get balance factor on left sub tree
			// cout << "bf of left subtree: " << bfTreeLeft << endl;
			if (bfTreeLeft == 0 || bfTreeLeft >= 1){ ++count; 	root = rotateRight(root);}
			else if (bfTreeLeft <= -1){
				castInt(root)->setLeft(rotateLeft(castInt(root)->getL()));
				root = rotateRight(root);
				++count;
			}
		}
		else if (bfTree < -1){ // right higher
			int bfTreeRight = getBalance(castInt(root)->getR()); // get balance factor on right sub tree
			// cout << "bf of right subtree: " << bfTreeRight << endl;
			if (bfTreeRight == 0 || bfTreeRight <= -1){ ++count;	root = rotateLeft(root);}
			else if (bfTreeRight >= 1){
				castInt(root)->setRight(rotateRight(castInt(root)->getR()));
				root = rotateLeft(root);
				++count;
			}
		}
		balanceTree(castInt(root)->balanceLeft(), count);
		balanceTree(castInt(root)->balanceRight(), count);
		balanceTree(root, count);
	}
	void InOrder(HuffNode *root){
        if (root->isLeaf()){ cout << castLeaf(root)->val() << endl; return;}
        InOrder(castInt(root)->getL());
        cout << root->weight() << endl;
        InOrder(castInt(root)->getR());
    }
	void clear(HuffNode *root){
		if (root->isLeaf()) { delete root; 
		return;}
		clear(castInt(root)->getL());
		clear(castInt(root)->getR());
		delete root;
	}
public:
	HuffTree(){root = nullptr;}	
    HuffTree(const char &val, int freq, int order) {
		ord = order;
        root = new LeafNode(val, freq);
    }
    ~HuffTree() {
		// clear(this->root);
	}
	void clear(){this->clear(this->root);}
    HuffNode* Root() { return root; }
	int pos(){return ord;}
    int weight() { return root->weight(); }
    HuffTree(HuffTree* l, HuffTree* r, int order) {
		ord = order;
        root = new IntNode(l->Root(), r->Root());
    }
	void balanceTree(int count){
		// if (count == 3)	return;
		balanceTree(this->root, count);
	}
    void BFS(){
        queue<HuffNode*> q;
        q.push(this->root);
        while (!q.empty()){
            HuffNode *temp = q.front();
            q.pop();
            if (temp->isLeaf()){cout <<castLeaf(temp)->val()<<endl;}
            else{        
                cout << temp->weight() << endl;
                q.push(castInt(temp)->getL());
                q.push(castInt(temp)->getR());
            }
        }
    }
	void InOrder(){InOrder(this->root);}
};

class BSTree{
	protected:
		struct Node{
			int data;
			Node *left;
			Node *right;
			Node (const int &a) : data(a), left(nullptr), right(nullptr){}
			~Node(){}
		};
		Node *root;
		void clear(Node *root){
			if (root == nullptr)	return;
			clear(root->left);
			clear(root->right);
			delete root;
		}
		void insert(Node *&root, const int &a){
			if (root == nullptr){
				root = new Node(a);
				return;
			}
			else{
				if (root->data > a)	insert(root->left, a);
				else insert(root->right, a);
			}
		}
		void remove(Node *&root, const int &data){
			if (root == nullptr)	return;
			if (root->data == data){
				if (root->left && root->right){
					Node *p = root->right;
					while (p->left) p = p->left;
					root->data = p->data;
					remove(root->right, root->data);
				}
				else if (root->left){
					Node *temp = root;
					root = root->left;
					delete temp;
				}
				else if (root->right){
					Node *temp = root;
					root = root->right;
					delete temp;
				}
				else{
					delete root;
					root = nullptr;
				}
				return;	
			}
			else if (root->data > data) remove(root->left, data);
			else remove(root->right, data);
		}
		void InOrder(Node *root){
			if (root == nullptr)	return;
			InOrder(root->left);
			cout << root->data<< endl;
			InOrder(root->right);
		}
		void getPreOrder(Node *root, vector<int> &res){
			if (root == nullptr)	return;
			res.push_back(root->data);
			getPreOrder(root->left, res);
			getPreOrder(root->right, res);
		}
	public:
		BSTree():root(nullptr){}
		~BSTree(){this->clear();}
		void clear() { this->clear(this->root);}
		void insert(const int &a){
			this->insert(this->root, a);
		}
		void remove(const int &a){
			this->remove(this->root, a);
		}
		void InOrder(){
			InOrder(this->root);
		}
		vector<int> getPreOrder(){
			vector<int> res;
			getPreOrder(this->root, res);
			return res;
		}
};
struct CompareHuffTree{
	bool operator()(HuffTree *a,HuffTree *b){return a->weight() != b->weight() ? a->weight() > b->weight() : a->pos() > b->pos();}
};
HuffTree* buildHuff(const vector<pci>& v) {
    priority_queue<HuffTree*, vector<HuffTree*>, CompareHuffTree> mHT;
	int count = 0;
    for (auto it : v){
        HuffTree *temp = new HuffTree(it.first, it.second, count++);
        mHT.push(temp);
    }
	HuffTree *left = nullptr, *right = nullptr, *temp = nullptr;
    while((int)mHT.size() > 1){
    	left = mHT.top(); mHT.pop();
        right = mHT.top(); mHT.pop();
        temp = new HuffTree(left, right, count++);
		int count = 0;
		temp->balanceTree(count);
        mHT.push(temp); 
		delete left;
		delete right;
    }
    return mHT.top();
}


// function field
ll countWayToGetTheSameBST(vector<int> &nums){
	if ((int)nums.size() <= 1)	return (int)nums.size() % MAXSIZE;	
	int n = nums.size();
    vector<vector<int>> comb(n + 1, vector<int>(n + 1));
    comb[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
	        comb[i][j] = (comb[i - 1][j - 1]%MAXSIZE + comb[i - 1][j]%MAXSIZE)%MAXSIZE;
        }
    }
    function<ll(vector<int>&)> dfs = [&](vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        ll res = comb[n - 1][left.size()];
        res = ((res%MAXSIZE) * (dfs(left)%MAXSIZE))%MAXSIZE;
        res = ((res%MAXSIZE) * (dfs(right)%MAXSIZE)) % MAXSIZE;
        return (int)res;
    };
    ll res = dfs(nums);
	return res % MAXSIZE;
}
void encodeCharHuffTree(map<char, string> &m, HuffTree *t){
	queue<pair<HuffNode*, string>> q;
	q.push({t->Root(), ""});
	while (!q.empty()){
		auto f = q.front();
		q.pop();
		if (f.first->isLeaf())
			m[dynamic_cast<LeafNode*>(f.first)->val()] = f.second;
		else{
			q.push({castInt(f.first)->getL(), f.second+'0'});
			q.push({castInt(f.first)->getR(), f.second+'1'});
		}
	}
}
int BintoDec(const string &bin){
	int temp = 0;
	for (int i=0; i<(int)bin.size(); i++)	temp = temp*2+((int)bin[i]-48);
	return temp;
}
string getNameAfterEncode(const string &name,  map<char, string> &m,  map<char, char> &mapping){
	string res = "";
	for (int i=0; i<(int)name.size(); i++){
		char c = mapping[name[i]];
		res += m[c];
	}
	return res;
}
void CaesarEncrypt(char &x, int num, map<char, char> &m){
	if (num > 26) num %= 26;
	if (x >= 'a' && x <='z'){
		int e = (int)x + num;
		e = e > (int)'z'? e-26 : e;
		m[x] = e;
		x = (char)e;
	}
	else if (x >= 'A' && x <='Z'){
		int e = (int)x + num;
		e = e > (int)'Z'? e-26 : e;
		m[x] = e;
		x = (char)e;
	}
}

void LAPSE(const string &name){
	// sort char in the string before process
	m.clear();
	//mapping char in name
	map<char, char> afterEncrypt;
	for (int i=0; i<(int)name.length(); i++){
        m[name[i]].first++;
        if (m[name[i]].first == 1) m[name[i]].second = i;
    }
	if ((int)m.size() < 3)	return;
	// create vector X to store character in name
    vector<pci> X;
    for (auto it : m) X.push_back({it.first, it.second.first});
    	// Caesar secure
	for (auto &it : X) CaesarEncrypt(it.first, it.second, afterEncrypt);
	
	m.clear();
	// gather the same character again
	for (auto it: X){
		if (m[it.first].first == 0) m[it.first].first = it.second;
		else				m[it.first].first+=it.second;
	}
	if ((int)m.size() == 1){
		auto it = m.begin();
		if (latestHuffTree){	latestHuffTree->clear(); delete latestHuffTree;}
		latestHuffTree = new HuffTree((*it).first, (*it).second.first, 0);
		SukunaRes->push(1, 0);
		return;
	}
	X.clear();
	for (auto it : m) X.push_back({it.first, it.second.first});
	sort(all(X), [](const pci &a, const pci &b){return a.second != b.second ? a.second < b.second : ((a.first >='a' && a.first <='z' && b.first >='a' && b.second <='z') || (a.first >='A' && a.first <='Z' && b.first >='A' && b.first <='Z'))? a.first < b.first : (a.first >= 'a' && a.first <='a' && b.first >='A' && b.first <='Z')?true:a.first > b.first;});
	// create hufftree
	if (latestHuffTree){ latestHuffTree->clear(); delete latestHuffTree; }
	latestHuffTree = buildHuff(X);
	// encode char in huff tree
	map<char, string> encodeChar; 
	encodeCharHuffTree(encodeChar, latestHuffTree);
	string nameafterEncode = getNameAfterEncode(name, encodeChar, afterEncrypt);
	// cout << "nameafterEncode: " << nameafterEncode << endl;
	reverse(all(nameafterEncode));
	string strtoDec = nameafterEncode.substr(0,  min(10, (int)nameafterEncode.size()));
	// cout << "strtoDec: " << strtoDec << endl;
	int result = BintoDec(strtoDec);
	// cout << "result: " << result << endl;
	//cout << result << endl;
	// cusTree->BFS();
	if (result & 1){
		if (!GojoRes[result % MAXSIZE + 1]) GojoRes[result % MAXSIZE + 1] = new BSTree();
		GojoRes[result % MAXSIZE + 1]->insert(result);
		GojoTime[result % MAXSIZE + 1].push(result);
	}
	else
		SukunaRes->push(result % MAXSIZE + 1, result);
	X.resize(0);
	X.shrink_to_fit();
	afterEncrypt.clear();
	encodeChar.clear();
}
void KOKUSEN(){
	for (auto &it : GojoRes){
		if (it.second){
			// cout << "zone " << it.first << " of GojoRes" << endl; 
			vector<int> pre = it.second->getPreOrder();
			// cout << "preorder: " ;
			// for (int x : pre) 	cout << x <<' ';
			// cout << endl;
			int Y = countWayToGetTheSameBST(pre);
			// cout << "Y: " << Y << endl;
			Y = min(Y, (int)GojoTime[it.first].size());
			while (!GojoTime[it.first].empty() && Y--){
				int CusToRemove = GojoTime[it.first].front(); GojoTime[it.first].pop();
				it.second->remove(CusToRemove);
			}
			pre.resize(0);
			pre.shrink_to_fit();
		}
	}
}
void KEITEIKEN(const int &num){
	vector<pair<int, vector<pair<int,int>>>> readyToRemove;
	// get the min heap 
	for (int i = 0; i<(int)SukunaRes->elements.size(); i++) readyToRemove.push_back(SukunaRes->elements[i]);
	// sort before process
	sort(all(readyToRemove), [](const pair<int, vector<pair<int,int>>> &a, const pair<int, vector<pair<int,int>>> &b){return a.second.size() != b.second.size() ? a.second.size() < b.second.size() : a.first < b.first;});
	int n = min(num, (int)readyToRemove.size());
	for (int i=0; i<n; i++){
		int nOfCusToSack = min(num, (int)readyToRemove[i].second.size());
		int j = 0; 
		int ID = readyToRemove[i].second.front().first;
		for (int k = 0; k < nOfCusToSack; k++){
			cout << readyToRemove[i].second[j].second << '-' <<ID << endl;
			++j;
		}
		if (nOfCusToSack == (int)readyToRemove[i].second.size())// customer in zone ID at Sukuna has been sacked all
			SukunaRes->remove(ID);
		else // not sacked all the cus
			SukunaRes->Keiteken(ID, nOfCusToSack);
	}
	readyToRemove.resize(0);
	readyToRemove.shrink_to_fit();
}
void HAND(){
	if (latestHuffTree) latestHuffTree->InOrder();
}
void LIMITLESS(const int &num){
	if (GojoRes[num])  GojoRes[num]->InOrder();
}
void CLEAVE(const int &num){
	if ((int)SukunaRes->elements.size() == 0)	return;
	// cout << "Num of zone has customer: " << SukunaRes->elements.size() << endl;
	// cout << "preoderSukuna: " << endl;
	SukunaRes->partial_CLEAVE(0, num);
}

void simulate(string filename){
	// freopen("output.txt", "w", stdout);
	// clock_t start, end;
    // start = clock();
	SukunaRes = new Heap();
	ifstream ss(filename);
	string instr;
	while (ss >> instr){
		if (instr == "MAXSIZE"){
			int size;
			ss >> size;
			MAXSIZE = size;
		}
		else if (instr == "LAPSE"){
			// cout << "LAPSE" << endl;
			string name;
			ss >> name;
			LAPSE(name);
		}
		else if (instr == "KOKUSEN"){
			// cout << "KOKUSEN" << endl;
			KOKUSEN();
		}
		else if (instr == "KEITEIKEN"){
			int num;
			ss >> num;
			// cout << "KEITEIKEN " << num <<endl;
			KEITEIKEN(num);
		}
		else if (instr == "HAND"){
			// cout << "HAND" << endl;
			HAND();
		}
		else if (instr == "LIMITLESS"){
			int num;
			ss >> num;
			// cout << "LIMITLESS " << num << endl;
			LIMITLESS(num);
		}
		else if (instr == "CLEAVE"){
			int num;
			ss >> num;
			// cout << "CLEAVE " << num << endl;
			CLEAVE(num);
		}
	}
	for (auto &it : GojoRes){
		if (it.second) delete it.second;
	}
	if (latestHuffTree){
		latestHuffTree->clear();
		delete latestHuffTree;
		latestHuffTree = nullptr;
	}
	m.clear();
	GojoRes.clear();
	GojoTime.clear();
	delete SukunaRes;
	// end = clock();
    // // Calculating total time taken by the program.
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cerr << "Time taken by program is : " << fixed 
    //      << time_taken << setprecision(5);
    // cerr << " sec " << endl;
	return;
}