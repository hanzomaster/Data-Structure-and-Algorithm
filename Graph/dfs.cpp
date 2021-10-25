// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <map>
#include <list>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
	map<int, bool>      visited;
	map<int, list<int>> adj;

public:
	// function to add an edge to graph
	void addEdge(int v, int w) {
		adj[v].push_back(w);    // Add w to v’s list.
	}

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v) {
		// Mark the current node as visited and
		// print it
		visited[v] = true;
		cout << v << " ";

		// Recur for all the vertices adjacent
		// to this vertex
		for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				DFS(*i);
	}
};

int main(int argc, char const *argv[]) {
	Graph g;
	int   n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		g.addEdge(node1, node2);
	}
	int beginAt;
	cin >> beginAt;
	g.DFS(beginAt);

	return 0;
}
