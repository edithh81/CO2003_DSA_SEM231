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
    static T* Partition(T* start, T* end){
        T *pivot = start;
        T *i = start;
        T *j = end;
        do{
            do{
                ++i;
            }while (*i < *pivot);
            do{
                --j;
            }while (*j > *pivot);
            swap(*i, *j);   
        } while(i<j);
        swap(*i, *j);
        swap(*pivot, *j);
        return j;
    } ;
public:
    static void QuickSort(T* start, T* end){
        if (start < end){
            T *pivot = Partition(start, end);
            cout  << pivot - start << ' ';
            QuickSort(start, pivot);
            QuickSort(pivot+1, end);
        }
    } ;
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";
    return 0;
}