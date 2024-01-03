#include <bits/stdc++.h>
using namespace std;
#define EDITH81
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define REP(i, b) for(int i = 0; i < b; i++)
#define PER(i, b) for(int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(),x.end()
using pii = pair<int, int>;

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T>
class SLinkedList {
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList():head(nullptr), tail(nullptr), count(0){

    };

    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    void    toString(){
        Node *tmp = head;
        while (tmp){
            cout << tmp->data << ' ';
            tmp = tmp -> next;
        }
    }
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList , bool begin );
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};
    template <class T>
    void SLinkedList<T>::add(const T &e) {
        if (count == 0)
            head = tail = new Node(e, nullptr);
        
        else
            tail = tail->next = new Node(e, nullptr);
        
        ++count;
        
    }

    template<class T>
    void SLinkedList<T>::add(int index, const T &e) {
        if (index < 0 || index >count)
            throw std :: out_of_range("the input index is out of range!");
        else{
            if (index == 0){
                if (head == nullptr){
                    this->add(e);
                    return;
                }
                Node *p = new Node(e,head);
                head = p;
            }
            else{
                Node *p = head;
                while (index >1 && p->next!=nullptr){
                    p = p->next;
                    --index;
                }
                Node *new_node = new Node(e, p->next);
                p->next = new_node;
            }
        ++count;
        }
    }
    template<class T>
    int SLinkedList<T>::size() {
        return count;
    }
    template<class T>
    T SLinkedList<T>::get(int index) {
        int i = 0;
        for (Node *p = head; p!=nullptr; p = p->next){
            if (i == index)
                return p->data;
            ++i;
        }
        return 0;
    }

    template <class T>
    void SLinkedList<T>::set(int index, const T& e) {
        if (index < 0 || index > this->count)
            return;
        int i = 0;
        for (Node **p = &head; p!=nullptr; p=&((*p)->next)){
            if (i == index){
                (*p)->data = e;
                break;
            }
            ++i;
        }
    }

    template<class T>
    bool SLinkedList<T>::empty() {
        return !this->count;
    }

    template<class T>
    int SLinkedList<T>::indexOf(const T& item) {
        int res = -1;
        int i = 0;
        for (Node *p = head; p!=nullptr; p=p->next){
            if (p->data == item){
                res = i;
                break;
            }
            ++i;
        }
        return res;
    }

    template<class T>
    bool SLinkedList<T>::contains(const T& item) {
        for (Node *p = head; p!=nullptr; p=p->next)
            if (p->data == item)
                return true;

        return false;
    }
    template <class T>
    T SLinkedList<T>::removeAt(int index)
    {
        if (index <0 || index >= count)
            throw std::out_of_range("index is out of range");
        if (index){
            Node *p = head;
            for (int i=0; i<index-1; i++)
                p = p->next;
            
            T val = p->next->data;
            Node *tmp = p->next;
            p->next = tmp->next;
            if (index == count -1)
                tail = p; 
            --this->count;
            delete tmp;
            return val;
        }
        T val = head->data;
        Node *p = head;
        head = p->next;
        --this->count;
        delete p;
        return val;
    }

    template <class T>
    bool SLinkedList<T>::removeItem(const T& item)
    {
        if (this->count==0)
            return false;
        Node *cur = head;
        Node *prev = nullptr;
        while (cur != nullptr && cur->data !=item){
            prev =cur;
            cur = cur->next;
        }
        if (cur == nullptr)
            return false;
        
        if (prev == nullptr){
            head = cur->next;
            delete cur;
        }
        else{
            prev->next = cur->next;
            if (cur->next == nullptr)
                tail = prev;
            delete cur;
        }
        --this->count;
        return true;
    }

    template<class T>
    void SLinkedList<T>::clear(){
        if (this->count == 0){
            head = tail = nullptr;
            return;
        }
        
        while (head){
            Node *p =head;
            head = p->next;
            delete p;
        }
        this->count = 0;
    }
   template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
   this->pList = pList;
   if (begin){
        if (pList != nullptr){
            this->current = pList->head;
            this->index = 0;
        }
        else{
            this->current = nullptr;
            this->index = -1;
        }
   }
   else{
        this->current = nullptr;
        if (pList != nullptr)
            this->index = pList->size();
        else
            this->index = 0;
   }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
   this-> current = iterator.current;
   this-> index = iterator.index;
   this->pList = iterator.pList;
   return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
   if (this->current == nullptr)
        throw std::out_of_range("Segmentation fault!");
    if (this->index == 0){
        this->pList->head = this->pList->head->next;
        delete this->current;
        this->current = nullptr;
        this->index = -1;
    }
    else{
        Node *tmp = this->pList->head;
        int idx = this->index;
        while (tmp && idx>1){
            --idx;
            tmp = tmp->next;
        }
        tmp->next = this->current->next;
        delete this->current;
        this->current = tmp;
        --this->index;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e){
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
   if (this->current)
        this->current->data = e;
   else
        throw std::out_of_range("Segmentation fault!");
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
   if (this->current)
        return this->current->data;
    throw std::out_of_range("Segmentation fault!");
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
   return !(this->current == iterator.current && this->index == iterator.index);
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->index == this->pList->count)
         throw std::out_of_range("Segmentation fault!");

    if (this->index == -1){
        this->current = this->pList->head;
    }
    else
        this->current = this->current->next;
    
    ++this->index;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->index == this->pList->count)
         throw std::out_of_range("Segmentation fault!");
    
    Iterator temp(*this);
    ++*this;
    return temp;
}
class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it=this->terms->begin();
        cout << "[";
        for ( ; it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};
void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if (term.coeff == 0)
        return;
    SLinkedList<Term> :: Iterator it = this->terms->begin();
    int size = this->terms->size();
    int i = 0;
    while(it != this->terms->end() && (*it).exp > term.exp && i<size){
        ++it;
        ++i;
    }
    
    if (i == size)
        this->terms->add(term);
    else if ((*it).exp == term.exp){
        (*it).coeff+=term.coeff;
        if ((*it).coeff == 0)
            this->terms->removeAt(i);
    }
    else
        this->terms->add(i, term);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    Term terms(coeff, exp);
    this->insertTerm(terms);
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    
    Polynomial *poly = new Polynomial();
poly->insertTerm(6.0, 2);
poly->insertTerm(4.0, 5);
poly->insertTerm(4.0, 3);
poly->insertTerm(6.0, 5);
poly->insertTerm(-1.0, 0);
poly->insertTerm(-6.0, 6);
poly->insertTerm(6.0, 6);
poly->print();


    
    return 0;
}