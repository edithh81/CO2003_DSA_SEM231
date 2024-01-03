#include <bits/stdc++.h>
using namespace std;
#define EDITH81
using ll = long long;
using ull = unsigned long long;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, b) for (int i = 0; i < b; i++)
#define PER(i, b) for (int i = b - 1; i >= 0; i--)
#define fi first
#define se second
#define all(x) x.begin(), x.end()
using pii = pair<int, int>;

const ll LINF = 1e18 + 5;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList(){};
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString(){
        string res = "";
        res += "[ ";
        Node *tmp = head;
        while (tmp){
            res+=to_string(tmp->data);
            res+=' ';
            tmp = tmp->next;
        }
        res+="]";
        return res;
    };
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
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
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    bool empty() ;
    int size() ;
    void clear() ;
};
template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    ++count;
    if (head == nullptr){
        head = tail = new Node(e);
        return;
    }
    else{
        tail->next = new Node(e);
        tail->next->previous = tail;
        tail = tail->next;
    }
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node *p = this->head;
    if (index == 0){
        if (p == nullptr){
            ++count;
            head = tail = new Node(e);
            return;
        }
        else{
            ++count;
            Node *tmp = new Node(e);
            tmp->next = head;
            head->previous = tmp;
            head = tmp;
        }
    }
    else if (index == count)
        this->add(e);
    else{
        ++count;
        for (int i=0; i<index-1 && p; i++)
            p = p->next;
        
        Node *tmp = new Node(e);
        p->next->previous = tmp;
        tmp->next = p->next;
        tmp->previous = p;
        p->next = tmp;
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node *p = this->head;
    for (int i=0; i<index && p; i++)
        p = p->next;
    
    if (p)  return p->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    Node **p = &this->head;
    for (int i=0; i<index; i++)
        p = &((*p)->next);
    
    (*p)->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return !count;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int idx = -1;
    Node *p = this->head;
    for (int i=0; i<count; i++){
        if (p->data == item){
            idx = i;
            break;
        }
        p = p->next;
    }
    return idx;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node *p = this->head;
    for (int i=0; i<count; i++){
        if (p->data == item)
            return true;
        p = p->next;
    }
    return false;
    
}
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    --count;
    T val;
    if (index == 0){
        Node *tmp = head;
        val = tmp->data;
        head = head->next;
        if (head)
            head->previous = nullptr;
        else head = tail = nullptr;
        delete tmp;
    }
    else{
        Node *p = this->head;
        for (int i=0; i<index-1; i++)
            p = p->next;
        val = p->next->data;
        Node *tmp = p->next;
        // case tail 
        if (p->next->next){
            tmp->next->previous = p;
            p->next = tmp->next;
            delete tmp;
        }
        else{
            p->next = nullptr;
            tail = p;
            delete tmp;
        }
    }
    return val;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int idx = this->indexOf(item);
    if (idx == -1)  return false;
    this->removeAt(idx);
    return true;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (count){
        this->removeAt(0);
    }
}
/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{   
    this->pList = pList;
    if (begin){
        if (pList && pList->size() > 0){
            current = pList->head;
            index = 0;
        }
        else{
            current = nullptr;
            index = -1;
        }
    }
    else{
        current = nullptr;
        if (pList)
            index = pList->size();
        else
            index = 0;
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current)
        current->data = e;
    else
        throw std::out_of_range("Segmentation fault!");
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (current)
        return current->data;
    throw std::out_of_range("Segmentation fault!");
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
   Node *tmp = pList->head;
   while (tmp != current)
        tmp = tmp->next;
   
   --pList->count;
   Node *prevtemp = tmp->previous;
   Node *nexttemp = tmp->next;
    if (prevtemp)
        prevtemp->next = nexttemp;
    else{
        pList->head = pList->head->next;
        if (pList->head)   pList->head->previous = nullptr;
        else pList->head = pList->tail = nullptr;
    }
    if (nexttemp)
        nexttemp->previous = prevtemp;
   current = current->previous;
   --index;
   if (current == nullptr)
        ++current;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    return !((current == iterator.current) && (index == iterator.index));
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (current == nullptr || pList == nullptr || index == pList->size())
        throw std::out_of_range("Segmentation fault!");
    
    if (index == -1)
        current = pList->head;
    else    current = current->next;
    ++index;
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    if (index == pList->size())
        throw std::out_of_range("Segmentation fault!");
    Iterator temp(*this);
    ++(*this);
    return temp;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    DLinkedList<int> list;
int size = 10;
for (int idx = 0; idx < size; idx++)
{
    list.add(idx);
}

DLinkedList<int>::Iterator it = list.begin();
for(; it != list.end(); it++)
{
    it.remove();
}
cout << list.toString();
    
    return 0;
}