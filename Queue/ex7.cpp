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
// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n) {
    queue<ll> q;
    q.push(2);
    q.push(5);
    for (int i=3; i<=n; i++){
        ll f = q.front(); q.pop();
        q.push(f*10 + 2);
        q.push(f*10 + 5);
    }
    q.pop();
    return q.front();
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int n;
    cin >> n;
    cout << nthNiceNumber(n) << endl;
    return 0;
}