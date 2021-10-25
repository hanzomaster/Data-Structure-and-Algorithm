#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <climits>
using namespace std;
#define INF (unsigned)!((int)0)

const int              MAX = 2e4;
vector<pair<int, int>> graph[MAX];

bool visit[MAX];
int  dist[MAX];

multiset<pair<int, int>> s;
int                      parent[MAX];    // used to print the path

int main(int argc, char const *argv[]) {
	for (int i = 0; i < MAX; i++) {
		parent[i] = -1;
		dist[i] = INT_MAX;
		visit[i] = false;
	}

	int nodes, edges, source_node, node_for_path;
	cin >> nodes >> edges >> source_node >> node_for_path;

	for (auto i = 0; i < edges; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));    //Comment it to make the Directed Graph
	}
	dist[source_node] = 0;
	s.insert(make_pair(0, source_node));

	while (!s.empty()) {
		pair<int, int> elem = *s.begin();
		s.erase(s.begin());
		int node = elem.second;
		if (visit[node]) continue;
		visit[node] = true;
		for (size_t i = 0; i < graph[node].size(); ++i) {
			int dest = graph[node][i].first;
			int w = graph[node][i].second;
			if (dist[node] + w < dist[dest]) {
				dist[dest] = dist[node] + w;
				parent[dest] = node;
				s.insert(make_pair(dist[dest], dest));
			}
		}
	}
	cout << "NODE" << '\t' << "DISTANCE" << endl;
	for (auto i = 0; i < nodes; ++i) {
		cout << i << '\t' << dist[i] << endl;
	}
	/*----PRINT SHORTEST PATH FROM THE SOURCE NODE TO THE NODE REQUESTED-------*/
	int        dest_node = node_for_path;
	stack<int> path;
	while (parent[node_for_path] != source_node) {
		path.push(node_for_path);
		node_for_path = parent[node_for_path];
	}
	path.push(node_for_path);
	path.push(source_node);
	cout << "Shortest Path from " << source_node << " to " << dest_node << ":" << endl;
	while (!path.empty()) {
		if (path.size() == 1) cout << path.top();
		else
			cout << path.top() << "->";
		path.pop();
	}
	return 0;
}
