#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2'000;
const int INF = 3'000'000;

vector<pair<int,int>> adj[MAX_N + 1];
vector<int> ts;

vector<int> dijk(int start) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	vector<int> dist(MAX_N + 1, INF);
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int node = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (dist[node] < d) continue;

		for (int i = 0; i < adj[node].size(); i++) {
			int next = adj[node][i].first;
			int cost = adj[node][i].second;

			if (dist[next] > dist[node] + cost) {
				dist[next] = dist[node] + cost;
				pq.push({ dist[node] + cost, next });
			}
		}
	}
	return dist;
}



int main() {
	int T; cin >> T;

	while (T--) {
		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;
		
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
		}
		ts.clear();

		for (int i = 0; i < m; i++) {
			int a, b, d; cin >> a >> b >> d;
			adj[a].push_back({ b,d });
			adj[b].push_back({ a,d });
		}
		
		for (int i = 0; i < t; i++) {
			int tt; cin >> tt;
			ts.push_back(tt);
		}

		vector<int> A = dijk(s);
		
		// g -> h -> t
		vector<int> B = dijk(h);

		// h -> g -> t
		vector<int> C = dijk(g);

		sort(ts.begin(), ts.end());

		for (int i = 0; i < t; i++) {
			int target_node = ts[i];
			// s -> g -> h -> t == s -> t 최단?
			if (A[target_node] == A[g] + C[h] + B[target_node]) {
				cout << target_node << " ";
				continue;
			}
			// s -> h -> g -> t == s -> t 최단?
			if (A[target_node] == A[h] + B[g] + C[target_node]) {
				cout << target_node << " ";
				continue;
			}
		}
		cout << "\n";
		
	}
}