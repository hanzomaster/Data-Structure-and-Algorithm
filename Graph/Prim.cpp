#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		G[node1][node2] = weight;
		G[node2][node1] = weight;
	}
	int no_edge;    // number of edge

	// create a array to track selected vertex
	// selected will become true otherwise false
	int selected[n];


	// set number of edge to 0
	no_edge = 0;

	// the number of egde in minimum spanning tree will be
	// always less than (n -1), where n is number of vertices in
	//graph

	// choose 0th vertex and make it true
	selected[0] = true;

	int x;    //  row number
	int y;    //  col number

	// print for edge and weight
	cout << "Edge"
	     << " : "
	     << "Weight";
	cout << endl;
	while (no_edge < n - 1) {
		//For every vertex in the set S, find the all adjacent vertices
		// , calculate the distance from the vertex selected at step 1.
		// if the vertex is already in the set S, discard it otherwise
		//choose another vertex nearest to selected vertex  at step 1.
		int min = INT_MAX;
		x = 0;
		y = 0;

		for (int i = 0; i < n; i++)
			if (selected[i])
				for (int j = 0; j < n; j++)
					if (!selected[j] && G[i][j])    // not in selected and there is an edge
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
		cout << x << " - " << y << " :  " << G[x][y];
		cout << endl;
		selected[y] = true;
		no_edge++;
	}

	return 0;
}
