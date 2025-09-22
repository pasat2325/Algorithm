#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
#include <climits>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; cin >> N >> M;
	int A, B, C;
	vector<vector<pair<int,int>>> adj(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		adj[A].push_back({ B,C });
		adj[B].push_back({ A,C });
	}
	int ix, iy; cin >> ix >> iy;

	vector<int> dist(N + 1, 0);
	using Node = pair<int, int>;
	priority_queue<Node, vector<Node>> pq;

	dist[ix] = INT_MAX;
	pq.emplace( INT_MAX, ix );
	while (!pq.empty()) {
		int d = pq.top().first;
		int p = pq.top().second;
		pq.pop();

		if (d < dist[p]) continue;
		for (int i = 0; i < adj[p].size(); i++) {
			int np = adj[p][i].first;
			int w = adj[p][i].second;
			
			int ww = min(d, w);
			if (dist[np] < ww) {
				dist[np] = ww;
				pq.emplace(ww, np);
			}
		}
	}

	cout << dist[iy];
}