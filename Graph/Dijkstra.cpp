#include <iostream>
#include <climits>
#include <vector>
using namespace std;
// A utility function to find the vertex with minimum distance
// value, from the set of vertices not yet included in shortest
// path tree
int minDistance(int dist[], bool sptSet[], int n) {
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < n; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printPath(int parent[], int i) {
	printPath(parent, parent[i]);

	cout << i << ' ';
}

void printSolution(int dist[], int n, int parent[]) {
	cout << dist[1] << endl;
	printPath(parent, 1);
}

// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(vector<vector<int>> graph, int src, int end, int n) {
	int dist[n];    // The output array. dist[i] will hold
	                // the shortest distance from src to i

	// sptSet[i] will true if vertex i is included / in shortest
	// path tree or shortest distance from src to i is finalized
	bool sptSet[n];

	// Parent array to store shortest path tree
	int parent[n];

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < n; i++) {
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < n - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to src
		// in first iteration.
		int u = minDistance(dist, sptSet, n);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < n; v++)

			// Update dist[v] only if is not in sptSet, there is
			// an edge from u to v, and total weight of path from
			// src to v through u is smaller than current value of
			// dist[v]
			if (!sptSet[v] && graph[u][v] &&
			    dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	printSolution(dist, n, parent);
}

int main(int argc, char const *argv[]) {
	int n, m, s, e;
	cin >> n >> m >> s >> e;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		graph[node1][node2] = weight;
		graph[node2][node1] = weight;
	}
	dijkstra(graph, s, e, n);
	return 0;
}
