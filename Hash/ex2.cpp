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
int foldShift(long long key, int addressSize)
{
    string temp = to_string(key);
    int fold = 0;
    while (!temp.empty()){
        fold += stoi(temp.substr(0, addressSize));
        temp.erase(0, min(addressSize, (int)temp.size()));
    }
    int c = 1;
    while (addressSize--)   c*=10;
    return fold % c;
}
int rotation(long long key, int addressSize)
{
    int last = key%10;
    key/=10;
    string temp = to_string(last) + to_string(key);
    return foldShift(stoll(temp), addressSize);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    cout << rotation(600101, 2);
    
    return 0;
}