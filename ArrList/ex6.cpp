#include <bits/stdc++.h>
using namespace std;
#define EDITH81
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

int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    if ((int)words.size()==0)
        return 0;
    vector<int> F((int)words.size(), 1);
    int res = 1;
    for (int i=1; i<(int)words.size(); i++){
        if (words[i][0]==words[i-1][0])
            F[i] = max(F[i], F[i-1]+1);
        res = max(res, F[i]);
    }
    return res;
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words);
    return 0;
}