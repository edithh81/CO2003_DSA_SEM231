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
int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    deque<int> dq;
    int res = -1e6;
    for (int i=0; i<k; i++){
        res = max(res, nums[i]);
        while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (int i=k; i<(int)nums.size(); i++){
        while (!dq.empty() && nums[i] > nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        if (!dq.empty() && dq.front() == i-k)
            dq.pop_front();
        
        res+=nums[dq.front()];
    }
    return res;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<int> nums {1, 2, 4, 3, 6};
int k = 3;
cout << sumOfMaxSubarray(nums, k);
    return 0;
}