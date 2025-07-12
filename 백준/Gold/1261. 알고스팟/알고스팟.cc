#include <iostream>
#include <queue>
#define INF 101*101
using namespace std;
int n, m; // n : width, m : height
int map[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> dijk(int sx, int sy) {
	priority_queue <pair<int, pair<int, int>>> pq;
	vector<vector<int>> dist(101, (vector<int>(101, INF)));
	pq.push({ 0,{sx,sy} });
	dist[1][1] = 0;
	while (!pq.empty()) {
		int curr_weight = -pq.top().first;
		int nowx = pq.top().second.first;
		int nowy = pq.top().second.second;
		pq.pop();

		if (dist[nowx][nowy] < curr_weight) continue;

		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];
			if (nx > m || ny > n || nx < 1 || ny < 1) continue;

			int cost = curr_weight + map[nx][ny];
			if (cost < dist[nx][ny]) {
				dist[nx][ny] = cost;
				pq.push({ -cost,{nx,ny} });
			}
		}
	}
	return dist;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++) {
			map[i][j] = str[j - 1] - '0';
		}
	}

	vector<vector<int>> dist = dijk(1, 1);
	cout << dist[m][n];
}