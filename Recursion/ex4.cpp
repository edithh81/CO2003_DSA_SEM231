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

bool isPalindrome(string str){
    if (str.length() <= 1)
        return true;
    if (str[0] == ' ')
        return isPalindrome(str.substr(1,(int)str.size()-1));

    if (str.back() == ' ')
        return isPalindrome(str.substr(0, (int)str.size()-1));
    
    return (str[0] == str.back()) && isPalindrome(str.substr(1, (int)str.size()-2));

}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);

    cout << isPalindrome("mom") << endl;

    cout << isPalindrome("do geese see god");
    return 0;
}