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
void interleaveQueue(queue<int>& q){
    queue<int> f;
    queue<int> b;
    int sz = (int)q.size();
    for (int i=0; i<sz; i++){
        if (i<sz/2) f.push(q.front());
        else   b.push(q.front());
        q.pop();
    }
    for (int i=1; i<=sz; i++){
        if (i&1){
            q.push(f.front());
            f.pop();
        }
        else{
            q.push(b.front());
            b.pop();
        }
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    queue<int> q;
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int element; cin >> element;
        q.push(element);
    }
    interleaveQueue(q);
    while (!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
}