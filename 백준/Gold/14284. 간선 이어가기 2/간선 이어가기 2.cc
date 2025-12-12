#include <iostream>
#include <queue>
using namespace std;

const int MAX_V = 5'001;
const int MAX_E = 100'000;
const int MAX_W = 100;
const int INF = MAX_V * MAX_W;

int v, e; 

vector<pair<int, int>>adj[MAX_V];

vector<int> dijk(int start) {
	vector<int> dist(MAX_V, INF);
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int cd = -pq.top().first;
		pq.pop();

		if (dist[cur] < cd) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int nx = adj[cur][i].first;
			int w = adj[cur][i].second;

			if (dist[nx] > dist[cur] + w) {
				dist[nx] = dist[cur] + w;
				pq.push({ -dist[cur] + w, nx });
			}
		}
	}
	return dist;
}
int main() {
	cin >> v >> e;
	
	for (int i = 0; i < e; i++) {
		int x, y, w; 
		cin >> x >> y >> w;
		adj[x].push_back({ y,w });
		adj[y].push_back({ x,w });
	}

	int s, t; 
	cin >> s >> t;

	vector<int> dist = dijk(s);
	cout << dist[t];
}