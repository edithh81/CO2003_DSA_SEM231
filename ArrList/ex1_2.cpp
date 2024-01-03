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
template<class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
    void    to_string();
     bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
};
template<class T>
void ArrayList<T>::ensureCapacity(int cap){
   if (cap > capacity){
        int new_capacity = capacity * 1.5;
        T *new_arr = new T[new_capacity];
        for (int i = 0; i<this->count; i++)
            new_arr[i] = this->data[i];
        delete []this->data;
        this->capacity = new_capacity;
        this -> data = new_arr;
   }
}

template <class T>
void ArrayList<T>::add(T e) {
    this->ensureCapacity(this->count);
    *(this->data+count) = e;
    this->count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    if (index < 0 || index > count)
        throw std :: out_of_range("the input index is out of range!");
    else{
        ++this->count;
        this->ensureCapacity(this->count);
        for (T *p = this->data+count-1; p!=this->data+index; p--)
            *(p) = move(*(p-1));
        *(this->data+index) = e;
    }
}

template<class T>
int ArrayList<T>::size() {
    return this->count;
}

template<class T>
void ArrayList<T> :: to_string(){
    for (int i=0; i<count; i++)
        cout << this->data[i] << ' ';
}
template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index < 0 || index >= this->count)
        throw std :: out_of_range("index is out of range");
    else{
        int val = this->data[index];
        for (T *p = this->data+index; p!= this->data+this->count-1; p++ )
            *p = move(*(p+1));

        --this->count;
        return val;
    }
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
    if (this->count == 0)
        return false;
    int idx = -1;
    for (T *p = this->data; p!=this->data+count; p++ ){
       if (*p == item){
            idx = p-this->data;
            break;
       }
    }
    if (idx == -1)
        return false;
    for (T *p = this->data+idx; p!= this->data+this->count; p++ )
            *p = move(*(p+1));
    --this->count;
    return true;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
   if (this->data == nullptr)
        return;
    delete []this->data;
    this->count = 0;
    this->capacity = 5;
    this->data = new T[capacity];
}

int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    ArrayList<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.to_string();
    cout << endl;
    arr.removeItem(6);

    arr.to_string() ;
    cout << endl;
    cout << arr.size();
    return 0;
}