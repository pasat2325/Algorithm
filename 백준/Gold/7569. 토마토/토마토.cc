#include<iostream>
#include<queue>


using namespace std;

int m, n, h;
int map[100][100][100];
int dir[6][3] = { {1,0,0},{0,1,0}, {0,0,1}, {-1,0,0}, {0,-1,0}, {0,0,-1} };
queue<pair<pair<int, int>, int>> q;


void bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int nx = x + dir[j][0];
				int ny = y + dir[j][1];
				int nz = z + dir[j][2];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && map[nz][nx][ny] == 0) {
					q.push({ {nx,ny}, nz });
					map[nz][nx][ny] = 1;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					cout << -1;
					return;
				}
			}
		}
	}
	cout << cnt - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ {j,k}, i });
				}
			}
		}
	}
	bfs();

}