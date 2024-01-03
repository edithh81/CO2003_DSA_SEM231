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
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end){
        int n1 = middle-start+1, n2 = end-middle;
        if (n2 <= 0 || n1 <= 0)   return;
        int *a = new int[n1]; int *b = new int[n2];
        for (int i=0; i<n1; i++)
            a[i] = *(start+i);
        for (int i=0; i<n2; i++)
            b[i] = *(middle+i+1);
        
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2){
            if (a[i] <= b[j]) *(start+k) = a[i++];
            else *(start+k) = b[j++];
            ++k;
        }
        while (i < n1) {*(start+k) = a[i++]; ++k;}
        while (j < n2) {*(start+k) = b[j++]; ++k;}
        delete []a;
        delete []b;
    } ;
public:
    static void InsertionSort(T* start, T* end){
        int n = end-start;
        for (int i=1; i<n; i++){
            T temp = *(start+i);
            int pos = i - 1;
            while (pos >= 0 && temp < *(start+pos)){
                *(start+pos+1) = *(start+pos);
                --pos;
            }
            *(start+pos+1) = temp;
        }
    } ;
    // cout << "Merge " << i+1 << ": "; printArray(start, end);
    static void TimSort(T* start, T* end, int min_size){
        int n = end-start;
        for (int i = 0; i<n; i+=min_size){
            int left = i;
            int right = min(i+min_size-1, n - 1);
            InsertionSort(start+left, start+right+1);
        }
        cout << "Insertion Sort: "; printArray(start, end);
        int cnt = 1;
        for (int sz = min_size; sz < n; sz *= 2){
            for (int left = 0; left < n; left+=2*sz){
                int middle = left + sz - 1;
                int right = min(left + 2*sz -1, n -1);
                merge(start+left, start+middle, start+right);
                cout << "Merge " << cnt++ << ": "; printArray(start, end);
            }
        }
    } ;
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int array[] = { 3, 20, 18, 17 ,12, 13, 14, 15, 1, 2, 9, 6, 4, 7, 11, 16, 10, 8, 5, 19 };
    int min_size = 4;
    Sorting<int>::TimSort(&array[0], &array[20], min_size);
    return 0;
}