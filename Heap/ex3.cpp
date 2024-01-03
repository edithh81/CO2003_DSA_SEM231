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
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    while (index < numberOfElements){
        int cIdx = 2*index+1;
        if (cIdx >= numberOfElements)   return;
        if (cIdx+1 < numberOfElements && maxHeap[cIdx+1] > maxHeap[cIdx])  ++cIdx;
        if (maxHeap[index] >= maxHeap[cIdx])    return;
        int temp(move(maxHeap[index]));
        maxHeap[index] = move(maxHeap[cIdx]);
        maxHeap[cIdx] = move(temp);
        index = cIdx;
    }

}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    while (index){
        int pIdx = (index-1) >> 1;
        if (maxHeap[pIdx] > maxHeap[index]) return;
        int temp(move(maxHeap[index]));
        maxHeap[index] = move(maxHeap[pIdx]);
        maxHeap[pIdx] = move(temp);
        index = pIdx;
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    
    
    return 0;
}