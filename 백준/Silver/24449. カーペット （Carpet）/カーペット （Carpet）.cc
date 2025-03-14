#include <iostream>
#include <queue>
using namespace std;
int n, m;
char map[500][500];
int visited[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visited[sx][sy] = 1;
	while (!q.empty()) {
		int herex = q.front().first;
		int herey = q.front().second;
		int cnt = visited[herex][herey];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = herex + dx[i];
			int ny = herey + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && !(map[herex][herey] == map[nx][ny])) {
				if (nx == n - 1 && ny == m - 1) return cnt;
				else {
					q.push({ nx,ny });
					visited[nx][ny] = cnt + 1;
				}

			}
		}
	}
	return -1;

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs(0, 0);
}