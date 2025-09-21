#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	int ix, iy; cin >> ix >> iy;
	ix--; iy--;
	long long a, b; int c; cin >> a >> b >> c;
	vector<vector<int>> H(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> H[i][j];

	int tph = 0;
	int tpx = 0, tpy = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (tph < H[i][j]) {
				tph = H[i][j];
				tpx = i; tpy = j;
			}
		}
	const long long INF = (1LL << 60);
	vector<vector<long long>> dist(n, vector<long long>(m, INF));
	using Node = tuple<long long, int, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;

	dist[ix][iy] = 0;
	pq.emplace(0, ix, iy);

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	while (!pq.empty()) {
		Node cur_node = pq.top();
		long long d = get<0>(cur_node);
		int x = get<1>(cur_node);
		int y = get<2>(cur_node);
		pq.pop();
		if (d != dist[x][y]) continue;
		if (x == tpx && y == tpy) {
			cout << d << "\n";
			return 0;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			int dh = H[nx][ny] - H[x][y];
			if (abs(dh) > c) continue;
			long long w = (dh == 0) ? 1 : (dh > 0 ? 1LL * dh * a : 1LL * (-dh) * b);
			if (dist[nx][ny] > d + w) {
				dist[nx][ny] = d + w;
				pq.emplace(dist[nx][ny], nx, ny);
			}
		}
	}
	cout << -1 << "\n";
}