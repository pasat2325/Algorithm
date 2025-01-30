#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> pii; // 가중치,정점
const int INF = 200000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, start;
	cin >> v >> e >> start;

	vector<vector<pii>> adj(v + 1, vector<pii>());

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(w,v);
	}
	vector<int> dist(v + 1, INF);
	dist[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, start);

	while (!pq.empty())
	{
		int current_dist = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (current_dist > dist[u]) continue;

		for (auto edge : adj[u])
		{
			int weight = edge.first;
			int v = edge.second;
			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.emplace(dist[v], v);
			}
			
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}