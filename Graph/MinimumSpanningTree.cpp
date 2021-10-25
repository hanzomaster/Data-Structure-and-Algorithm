#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

struct Solution {
	int src, dest, weight;
	Solution() {
		src = 0;
		dest = 0;
		weight = 0;
	}
	Solution(int src, int dest, int weight) {
		this->src = src;
		this->dest = dest;
		this->weight = weight;
	}
};

// Function to find out minimum valued node
// among the nodes which are not yet included in MST
int minnode(int n, int keyval[], bool mstset[]) {
	int mini = numeric_limits<int>::max();
	int mini_index = 0;

	// Loop through all the values of the nodes
	// which are not yet included in MST and find
	// the minimum valued one.
	for (int i = 0; i < n; i++) {
		if (mstset[i] == false && keyval[i] < mini) {
			mini = keyval[i], mini_index = i;
		}
	}
	return mini_index;
}

// Function to find out the MST and
// the cost of the MST.
void findcost(int n, vector<vector<int>> graph) {
	// Array to store the parent node of a
	// particular node.
	int parent[n];

	// Array to store key value of each node.
	int keyval[n];

	// Boolean Array to hold bool values whether
	// a node is included in MST or not.
	bool mstset[n];

	// Set all the key values to infinite and
	// none of the nodes is included in MST.
	for (int i = 0; i < n; i++) {
		keyval[i] = numeric_limits<int>::max();
		mstset[i] = false;
	}

	// Start to find the MST from node 0.
	// Parent of node 0 is none so set -1.
	// key value or minimum cost to reach
	// 0th node from 0th node is 0.
	parent[0] = -1;
	keyval[0] = 0;

	// Find the rest n-1 nodes of MST.
	for (int i = 0; i < n - 1; i++) {
		// First find out the minimum node
		// among the nodes which are not yet
		// included in MST.
		int u = minnode(n, keyval, mstset);

		// Now the uth node is included in MST.
		mstset[u] = true;

		// Update the values of neighbor
		// nodes of u which are not yet
		// included in MST.
		for (int v = 0; v < n; v++) {
			if (graph[u][v] && mstset[v] == false &&
			    graph[u][v] < keyval[v]) {
				keyval[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}

	// Find out the cost by adding
	// the edge values of MST.
	int              cost = 0;
	vector<Solution> solution;
	for (int i = 1; i < n; i++) {
		cost += graph[parent[i]][i];
		// cout << parent[i] << ' ' << i << ' ';
		// cout << graph[parent[i]][i] << ' ';
		// cout << endl;
		solution.emplace_back(min(parent[i], i), max(parent[i], i), keyval[i]);
	}
	sort(solution.begin(), solution.end(), [](Solution s1, Solution s2) {
		if (s1.weight < s2.weight)
			return true;
		else if (s1.weight > s2.weight)
			return false;
		else {
			if (s1.src < s2.src)
				return true;
			else
				return false;
		}
	});
	cout << cost << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << solution[i].src << ' ' << solution[i].dest << ' ' << solution[i].weight;
		cout << endl;
	}
}

// Utility Program:
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		g[node1][node2] = weight;
		g[node2][node1] = weight;
	}
	findcost(n, g);
	return 0;
}
