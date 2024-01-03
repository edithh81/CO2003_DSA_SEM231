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
class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        Adjacency *res = new Adjacency();
        int j = 0;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(v);
        visited[v] = true;
        while (!q.empty()){
            int t = q.front(); q.pop();
            res->push(t);
            for (int i = 0; i<(int)adj[t].getSize(); i++){
                 if (!visited[adj[t].getElement(i)]) {
                    q.push(adj[t].getElement(i));
                    visited[adj[t].getElement(i)] = true;
                 }
            }
        }
        return res;
	}
    void DFS(int v, Adjacency *&res, vector<bool> &visited){
        res->push(v);
        visited[v] = true;
        for (int i = 0; i<(int)adj[v].getSize(); i++){
            if (!visited[adj[v].getElement(i)]){
                visited[adj[v].getElement(i)] = true;
                DFS(adj[v].getElement(i), res, visited);
            }
        }
    }   
    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        Adjacency *res = new Adjacency();
        vector<bool> visited(V, false);
        DFS(v, res, visited);
        return res;
	}
};
int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("oup.txt", "w", stdout);
    int V = 6;
int visited = 0;

Graph g(V);
Adjacency* arr = new Adjacency(V);
int edge[][2] = {{0,1},{0,2},{1,3},{1,4},{2,4},{3,4},{3,5},{4,5}};
    
for(int i = 0; i < 8; i++)
{
    g.addEdge(edge[i][0], edge[i][1]);
}
    
arr = g.BFS(visited);
arr->printArray();
delete arr;

    
    return 0;
}