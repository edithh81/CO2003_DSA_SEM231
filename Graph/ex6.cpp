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

int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	priority_queue<pii, vector<pii>, greater<pii>> Q;
    int n = 6;
    Q.push({0, src});
    vector<int> Dist(n, MAX);
    Dist[src] = 0;
    while (!Q.empty()){
        pii t = Q.top(); 
        Q.pop();
        int u = t.second, dis = t.first;
        if (dis > Dist[u]) continue;
        for (int i = 0; i<n; i++){
            if (i != u && graph[u][i] != 0){
                int w = graph[u][i];
                if (Dist[i] > Dist[u] + w){
                    Dist[i] = Dist[u] + w;
                    Q.push({Dist[i], i});
                }
            }
        }
    }
    return Dist[dst];
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
   int n = 6;
int init[6][6] = {
	{0, 10, 20, 0, 0, 0},
	{10, 0, 0, 50, 10, 0},
	{20, 0, 0, 20, 33, 0},
	{0, 50, 20, 0, 20, 2},
	{0, 10, 33, 20, 0, 1},
	{0, 0, 0, 2, 1, 0} };

int** graph = new int*[n];
for (int i = 0; i < n; ++i) {
	graph[i] = init[i];
}

cout << Dijkstra(graph, 0, 1);

    
    return 0;
}