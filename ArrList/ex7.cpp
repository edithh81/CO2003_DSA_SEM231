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

int equalSumIndex(vector<int>& nums) {
    // STUDENT ANSWER
    if((int)nums.size()==1)
        return 0;
    vector<int> prefix;
    for (int i=0; i<(int)nums.size(); i++){
        if (i==0)
            prefix.push_back(nums[0]);
        else prefix.push_back(nums[i]+prefix[i-1]);
    }
    for (int i=1; i<(int)prefix.size(); i++){
        if (prefix[i-1] == prefix[(int)prefix.size()-1]-prefix[i])
            return i;
    }
    return -1;

}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums);
    return 0;
}