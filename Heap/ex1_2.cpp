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
const int dy[4] = {0, -1, 0, 1};
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return !count;
}

template<class T>
T Heap<T>::peek(){
    if (count)
        return elements[0];
    return -1;
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i=0; i<count; i++)
        if (elements[i] == item)    return true;
    
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (count){
        elements[0] = move(elements[count-1]);
        --count;
        reheapDown(0);
        return true;
    }
    return false;
}
template<class T>
void Heap<T>::push(T item){
    if (count == capacity) ensureCapacity(count);
    elements[count] = item;
    ++count;
    reheapUp(count-1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T *temp = new T[count];
    for (int i=0; i<count; i++) temp[i] = move(elements[i]);
    delete []elements;
    capacity = count + minCapacity;
    elements = new T[capacity];
    for (int i=0; i<count; i++) elements[i] = move(temp[i]);
    delete []temp;
}

template<class T>
void Heap<T>::reheapUp(int position){
    while (position){
        int pos = (position-1) >> 1;
        if (elements[pos] > elements[position]) return;
        T temp(move(elements[position]));
        elements[position] = move(elements[pos]);
        elements[pos] = move(temp);
        position = pos;
    }
}
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i = 0; i<count; i++)   if (elements[i] == item)    return i;
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int idx = getItem(item);
    elements[idx] = move(elements[count-1]);
    --count;
    reheapUp(idx);
    reheapDown(idx);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    if (count == 0) return;
    delete []elements;
    count = 0;
    capacity = 10;
    elements = new T[capacity];
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    Heap<int> maxHeap;
    int arr[] = {42,35,30,15,20,21,18,3,7,14};
    for (int i = 0; i < 10; i++)
        maxHeap.push(arr[i]);
    maxHeap.printHeap();
    maxHeap.remove(42);
    maxHeap.remove(35);
    maxHeap.remove(30);
    maxHeap.printHeap();
    
    return 0;
}