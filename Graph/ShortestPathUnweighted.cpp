#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <climits>
using namespace std;

class Graph {
	map<int, bool>      visited;
	map<int, list<int>> adj;

public:
	void addEdge(int src, int dest) {
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}

	bool BFS(int &src, int &dest, vector<int> &pred, vector<int> &dist) {
		queue<int> q;

		for (size_t i = 0; i < dist.size(); ++i) {
			dist[i] = INT_MAX;
			pred[i] = -1;
		}

		visited[src] = true;
		dist[src] = 0;
		q.push(src);

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
				if (!visited[*i]) {
					visited[*i] = true;
					dist[*i] = dist[u] + 1;
					pred[*i] = u;
					q.push(*i);

					if (*i == dest)
						return true;
				}
		}
		return false;
	}

	void printShortestDistance(int start, int dest, int n) {
		vector<int> pred(n), dist(n);

		if (!BFS(start, dest, pred, dist)) {
			cout << "Given source and destination"
			     << " are not connected";
			return;
		}

		vector<int> path;
		int         crawl = dest;
		path.push_back(crawl);
		while (pred[crawl] != -1) {
			path.push_back(pred[crawl]);
			crawl = pred[crawl];
		}

		// distance from source is in distance array
		cout << "Shortest path length is : " << dist[dest];

		// printing path from source to destination
		cout << "\nPath is::\n";
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
	}
};

int main(int argc, char const *argv[]) {
	Graph g;
	int   n, m, start, dest;
	cin >> n >> m >> start >> dest;
	int node1, node2;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		g.addEdge(node1, node2);
	}
	g.printShortestDistance(start, dest, n);
	return 0;
}
