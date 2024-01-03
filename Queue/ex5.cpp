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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
// iostream, vector and queue are included
// Hint: use breadth-first-search
#define piii pair<int,pair<int,int>>
int secondsToBeRotten(vector<vector<int>>& grid) {
    queue<piii> q;
    int cF = 0, cR = 0;
    for (int i=0; i<(int)grid.size(); i++){
        for (int j=0; j<(int)grid[i].size(); j++){
            if (grid[i][j] == 2)
                q.push({0, {i,j}});
            else if (grid[i][j] == 1) ++cF;
        }
    }
    cR = q.size();
    if (cR == 0)    return -1;
    int anstime = 1;
    while (!q.empty()){
        piii f  = q.front();
        q.pop();
        int time = f.first;
        for (int k = 0; k<4; k++){
            int i1 = f.second.first+dx[k], j1 = f.second.second+dy[k];
            if (i1 >= 0 && i1 < (int)grid.size() && j1>=0 && j1<(int)grid[0].size() && grid[i1][j1] == 1){
                grid[i1][j1] = 2;
                --cF;
                q.push({time+1,{i1, j1}});
                anstime = max(anstime, time+1);

            }
        }
    }
    return (cF==0?anstime:-1);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
     int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
    return 0;
}