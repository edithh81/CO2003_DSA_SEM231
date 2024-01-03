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
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
    bool DFS(int v, vector<int> &colors){
        colors[v] = 1;
        for (int x : adj[v]){
            if (!colors[x]){
                colors[x] = 1;
                if (DFS(x,colors))   return true;
            }
            else if (colors[x] == 1)   return true;
        }
        colors[v] = 2;
        return false;
    }
	bool isCyclic()
	{
	    // Student answer
        vector<int> colors(V, 0);
        for (int i = 0; i<V; i++){
            if ( DFS(i, colors))
                return true;
        }
        return false;
	}
}; 
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    DirectedGraph g(8); 
int edege[][2] = {{0,6}, {1,2}, {1,4}, {1,6}, {3,0}, {3,4}, {5,1}, {7,0}, {7,1}};

for(int i = 0; i < 9; i++)
	g.addEdge(edege[i][0], edege[i][1]);

if(g.isCyclic()) 
	cout << "Graph contains cycle"; 
else
	cout << "Graph doesn't contain cycle"; 

    
    return 0;
}