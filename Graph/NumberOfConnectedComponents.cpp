#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

class Graph {
	map<int, bool>      visited;
	map<int, list<int>> adj;

public:
	void addEdge(int v, int w) {
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	void DFS(int start) {
		// Mark the current node as visited
		visited[start] = true;

		for (auto i = adj[start].begin(); i != adj[start].end(); ++i)
			if (!visited[*i])
				DFS(*i);
	}

	int numberOfConnectedComponents(int n) {
		int count = 0;

		for (int i = 0; i < n; ++i)
			if (!visited[i]) {
				DFS(i);
				count++;
			}
		return count;
	}
};

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	Graph g;
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		g.addEdge(node1, node2);
	}
	cout << g.numberOfConnectedComponents(n);
	return 0;
}
