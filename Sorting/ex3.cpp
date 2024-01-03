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
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    // TODO: Write your code here
   static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total){
        int sz = end-start;
        for (int i = cur_segment_total+segment_idx; i < sz; i+=cur_segment_total)
            for (int j = i; j >= cur_segment_total && *(start+j) < *(start+j-cur_segment_total); j-=cur_segment_total)
                swap(*(start+j), *(start+j-cur_segment_total));
    
    }
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases){
        --num_phases;
        for ( ; num_phases >= 0; num_phases--){
            cout << *(num_segment_list+num_phases) << " segments: ";
            for (int j=0; j<*(num_segment_list+num_phases); j++)
                sortSegment(start, end, j, *(num_segment_list+num_phases));
            
            printArray(start, end);
        }
    }
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    	
    int num_segment_list[] = { 1, 2, 5 };
    int num_phases = 3;
    int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
    return 0;
}