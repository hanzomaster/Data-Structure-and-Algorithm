#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph {
	map<int, bool>      visited;
	map<int, list<int>> adj;

public:
	void addEdge(int v, int w) {
		adj[v].push_back(w);
	}

	void BFS(int start) {
		queue<int> q;

		visited[start] = true;
		q.push(start);

		while (!q.empty()) {
			start = q.front();
			cout << start << ' ';
			q.pop();

			for (auto i = adj[start].begin(); i != adj[start].end(); ++i)
				if (!visited[*i]) {
					visited[*i] = true;
					q.push(*i);
				}
		}
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
	g.BFS(beginAt);
	return 0;
}
