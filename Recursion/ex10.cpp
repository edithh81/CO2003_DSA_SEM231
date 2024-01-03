#include <bits/stdc++.h>
using namespace std;

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
int solve(string :: iterator start, string :: iterator ending, int count, int ans){
    if (start == ending)
        return abs(count)+abs(ans);
    if (*start == ')'){
        if (count > 0) --count; // (
        else ++ans;
    }
    else    ++count;
    return solve(start+1, ending, count, ans);
}
int mininumBracketAdd(string s) {
    // STUDENT ANSWER
    if (s.empty())
        return 0;
    return solve(s.begin(), s.end(), 0, 0);
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    cout << mininumBracketAdd(")))((");
    
    return 0;
}