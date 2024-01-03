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
int findClosePara(const string &s, const int &index){
    if (s[index] == ')')
        return index;
    return findClosePara(s, index+1);
}
string pow_str(const string &s, const int &p){
    if (p==0)
        return "";
    return s + pow_str(s, p-1);
}
string expand(string s){
    size_t open = s.rfind('(');
    if (open == string :: npos) return s;

    int p = s[open-1] -'0';
    size_t close = findClosePara(s, open+2);
    string strInPara = s.substr(open+1, close-open-1);
    s.erase(open-1, close-open+2);
    s.insert(open-1, pow_str(strInPara, p));
    return expand(s);
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    cout << expand("2(ab3(cde)x)") << "\n";
    
    return 0;
}