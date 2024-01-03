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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        int n1 = middle-left+1, n2 = right-middle;
        int *a = new int[n1]; int *b = new int[n2];
        for (int i=0; i<n1; i++)
            a[i] = *(left+i);
        for (int i=0; i<n2; i++)
            b[i] = *(middle+i+1);
        
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2){
            if (a[i] <= b[j]) *(left+k) = a[i++];
            else *(left+k) = b[j++];
            ++k;
        }
        while (i < n1) {*(left+k) = a[i++]; ++k;}
        while (j < n2) {*(left+k) = b[j++]; ++k;}
        delete []a;
        delete []b;
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
        if (start >= end)   return;
       T *middle = start + (end-start)/2;
       mergeSort(start, middle);
       mergeSort(middle+1, end);
       merge(start, middle, end);
    }
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int arr[] = {0,2,4,3,1,4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);
    return 0;
}