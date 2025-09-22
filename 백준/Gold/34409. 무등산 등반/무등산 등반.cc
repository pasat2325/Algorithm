#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; cin >> N >> M;
	int ix, iy; cin >> ix >> iy;
	ix--; iy--;
	int a, b, c; cin >> a >> b >> c;
	vector<vector<int>>H(N, vector<int>(M));

	int tpx = -1, tpy = -1, tph = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int ih; cin >> ih;
			H[i][j] = ih;
			if (tph < H[i][j]) {
				tph = H[i][j];
				tpx = i; tpy = j;
			}
		}
	}

	const long long INF = 5e9;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	vector<vector<long long>> dist(N, vector<long long>(M, INF));
	using Node = tuple<long long, int, int>;
	priority_queue<Node, vector<Node>, greater<Node>> pq;

	dist[ix][iy] = 0;
	pq.emplace(0, ix, iy);

	while (!pq.empty()) {
		Node cur = pq.top();
		long long d = get<0>(cur);
		int cx = get<1>(cur);
		int cy = get<2>(cur);
		pq.pop();
		
		if (d != dist[cx][cy]) continue;

		if (cx == tpx && cy == tpy) {
			cout << d << "\n";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			int dh = H[nx][ny] - H[cx][cy];
			if (abs(dh) > c) continue;

			long long w = (dh == 0) ? 1 : ((dh > 0) ? 1LL * dh * a : 1LL * (-dh) * b);
			
			if (dist[nx][ny] > d + w) {
				dist[nx][ny] = d + w;
				pq.emplace(dist[nx][ny], nx, ny);
			}
		}
	}
	cout << -1 << "\n";
	return 0;

}