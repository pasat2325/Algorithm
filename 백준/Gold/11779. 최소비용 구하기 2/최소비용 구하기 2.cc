#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 1001
#define INF 1e9
using namespace std;

int n, m;
vector<pair<int,int>> adj[MAX_N]; //{w, e} 
int parent[MAX_N];

vector<int> dijk(int start) {
	vector<int> dist(n + 1,INF);
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int curr_weight = -pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();
		if (dist[curr_node] < curr_weight) continue;

		for (int i = 0; i < adj[curr_node].size(); i++) {
			int next_node = adj[curr_node][i].second;
			int next_weight = adj[curr_node][i].first;
			if (dist[next_node] > curr_weight + next_weight) {
				dist[next_node] = curr_weight + next_weight;
				pq.push({ -dist[next_node], next_node });

				parent[next_node] = curr_node;
			}
		}
	}
	return dist;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back({ weight, end });
	}
	int s, e;
	cin >> s >> e;
	vector<int> result = dijk(s);
	cout << result[e] << "\n";

	vector<int>path;
	int curr = e;
	while (curr != 0) {
		path.push_back(curr);
		curr = parent[curr];
	}
	reverse(path.begin(), path.end());
	cout << path.size() << "\n";
	for (auto i : path) cout << i << " ";
}

