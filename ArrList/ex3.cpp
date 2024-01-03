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
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    vector<int> prefix;
    for (int i=0; i<nums.size(); i++){
        if (i==0)
            prefix.push_back(nums[i]);
        else
            prefix.push_back(nums[i] -nums[i-1]);
    }
    for (int i=0; i<operations.size(); i++){
        prefix[operations[i][0]]+=operations[i][2];
        prefix[operations[i][1]+1]-=operations[i][2];
    }
    vector<int> res;
    int ans = 0;
    for (int i=0; i<prefix.size(); i++){
        ans+=prefix[i];
        res.push_back(ans);
    }
    return res;
}

int main(){
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    vector<int> res = updateArrayPerRange(nums, operations);
    for (int x : res)
        cout << x << ' ';
    return 0;
}