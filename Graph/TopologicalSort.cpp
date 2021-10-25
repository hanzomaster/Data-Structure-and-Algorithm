#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <stack>

using namespace std;

class Graph {
	map<int, vector<int>> adjlist;
	map<int, bool>        vis;
	stack<int>            order;

public:
	void addEdge(int u, int v) {
		adjlist[u].push_back(v);
	}

	void topological_dfs() {
		for (auto i : adjlist) {
			int node = i.first;
			if (!vis[node]) {
				dfshelper(node);
			}
		}
		print_order();
	}

	void dfshelper(int u) {
		vis[u] = true;
		for (auto i : adjlist[u]) {
			if (!vis[i])
				dfshelper(i);
		}
		order.push(u);
	}

	void print_order() {
		while (!order.empty()) {
			cout << order.top() << ' ';
			order.pop();
		}
	}
};

int main() {
	Graph g;
	int   n, m;
	cin >> n >> m;
	int node1, node2;
	for (int i = 0; i < m; i++) {
		cin >> node1 >> node2;
		g.addEdge(node1, node2);
	}
	g.topological_dfs();
	return 0;
}
