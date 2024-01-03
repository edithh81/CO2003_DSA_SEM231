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
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    //Helping functions go here
    static void reheapDown(T* start, int n, int idx){
        while (idx < n){
            int cIdx = idx*2+1;
            if (cIdx >= n)  return;
            if (cIdx + 1 < n && *(start+cIdx+1) > *(start+cIdx)) ++cIdx;
            if (*(start + idx) >= *(start+cIdx))    return;
            T temp(move(*(start+idx)));
            *(start+idx) = move(*(start+cIdx));
            *(start+cIdx) = move(temp);
            idx = cIdx;
        }
    }
    static void buildHeap(T* start, int n){
        for (int i=n/2; i>-1; i--)    Sorting<T> :: reheapDown(start, n, i);
    }
    static void heapSort(T* start, T* end){
        //TODO
        int n = end-start;
        Sorting<T> :: buildHeap(start, n);
        n--;
        while (n){
            T temp(move(*(start)));
            *start = move(*(start+n));
            *(start+n) = move(temp);
            Sorting<T>:: reheapDown(start, n, 0);
            --n;
        }
        Sorting<T>::printArray(start,end);
    }
    
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int arr[4] = { 4,2,9,1 };
    Sorting<int>::heapSort(&arr[0], &arr[4]);
    int arr1[4]={-1,0,2,3};
    Sorting<int>::heapSort(&arr1[0],&arr1[4]);

    return 0;
}