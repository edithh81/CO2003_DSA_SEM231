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
int pairMatching(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int i = 0, j = (int)nums.size()-1;
    while (i<j){
        if (nums[i] + nums[j] == target){
            ++res; 
            ++i; --j;
        }
        else if (nums[i] + nums[j] < target) ++i;
        else --j;
    }
    return res;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<int>items{1, 3, 5, 3, 7};
int target = 6;
cout << pairMatching(items, target);
    return 0;
}