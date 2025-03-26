#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int map[8][8];
int tempMap[8][8];
//int visited[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int safeCnt;

void bfs(int srcx, int srcy) {
	queue<pair<int, int>> q;
	q.push({ srcx, srcy });
	while (!q.empty()) {

		int herex = q.front().first;
		int herey = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = herex + dx[i];
			int ny = herey + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && tempMap[nx][ny] == 0) {
				tempMap[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}
}

void copy_map() {
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			tempMap[i][j] = map[i][j];
		}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) continue;
			int temp3 = map[i][j];
			map[i][j] = 1;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					if (map[k][l] != 0) continue;
					int temp2 = map[k][l];
					map[k][l] = 1;
					for (int v = 0; v < n; v++) {
						for (int p = 0; p < m; p++) {
							if (map[v][p] != 0) continue;
							int temp1 = map[v][p];
							map[v][p] = 1;
							copy_map();

							for (int x = 0; x < n; x++) 
								for (int y = 0; y < m; y++) {
									if (tempMap[x][y] == 2) bfs(x, y);
								}

							safeCnt = 0;
							for (int x = 0; x < n; x++)
								for (int y = 0; y < m; y++) {
									if (tempMap[x][y] == 0) safeCnt++;
								}
							ans = safeCnt > ans ? safeCnt : ans;

							map[v][p] = temp1;
						}
					}
					map[k][l] = temp2;
				}
			}
			map[i][j] = temp3;
		}
	}
	cout << ans;
}