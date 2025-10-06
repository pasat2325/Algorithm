#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1e7;
int n, m; // 집하장 개수, 간선 개수
vector<pair<int,int>> adj[201];

vector<int> dijk(int x) {
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	vector<int> dist(n + 1, INF);
	vector<int> prev(n + 1, -1);

	dist[x] = 0;
	pq.push({ 0, x });

	while (!pq.empty()) {
		int d = pq.top().first;
		int xx = pq.top().second;
		pq.pop();
		if (d > dist[xx]) continue;

		for (int i = 0; i < adj[xx].size(); i++) {
			int nx = adj[xx][i].first;
			int w = adj[xx][i].second;

			if (dist[nx] > d + w) {
				dist[nx] = d + w;
				prev[nx] = xx;
				pq.push({ d + w, nx });
			}
		}
	}
	return prev;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back({ y,z });
		adj[y].push_back({ x,z });
	}
	vector<vector<int>> res(n + 1, vector<int>(n + 1));
	for (int i = 1; i < n + 1; i++) {
		vector<int> prev = dijk(i);
		for (int j = 1; j < n + 1; j++) {
			if (i == j) {
				res[i][j] = 0;
				continue;
			}
			int p = j;
			while (true) {
				if (prev[p] == -1) {
					res[i][j] = 0;
					break;
				}
				if (prev[p] == i) {
					res[i][j] = p;
					break;
				}
				p = prev[p];
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (res[i][j] == 0) cout << '-' << " ";
			else cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}