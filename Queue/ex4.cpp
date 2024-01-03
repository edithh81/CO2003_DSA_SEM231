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
bool bfs(int u, vector<int> & color, vector<vector<int>> graph){
    queue<int> q;
    q.push(u);
    color[u] = 0;
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int x : graph[v]){
            if (color[x] == -1){
                color[x] = 1-color[v];
                q.push(x);
            }
            else if (color[x] == color[v])
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> graph) {
    vector<int> color((int)graph.size(), -1);
    color[0] = 1;
    for (int i=1; i<(int)graph.size(); i++){
        if (color[i] == -1){
            if (!bfs(i, color, graph))
                return false;
        }
    }
    return true;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
int n = 6;

vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}

isBipartite(graph) ? cout << "Yes" : cout << "No";
    return 0;
}