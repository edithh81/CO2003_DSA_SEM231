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

bool consecutiveOnes(vector<int>& nums) {
    // STUDENT ANSWER
    if (!nums.size())
        return false;

    int i = 0;
    while (nums[i] != 1 && i<(int)nums.size())
        ++i;
    
    if (i==(int)nums.size())
        return false;
    
    while(nums[i] == 1)
        ++i;
    
    if (i==(int)nums.size())
        return true;
    
    while (i<(int)nums.size()){
        if (nums[i] == 1)
            return false;
        ++i;
    }
    return true;
}
int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<int> nums {1,1,1,1,1};
    cout << consecutiveOnes(nums);
    return 0;
}