#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int n, m;

int grid[1000][1000];
int ans_grid[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

// 나올수 있는 0 영역의 최대 개수는 -> 모든 0이 서로 인접하지 않은 경우 == n * m / 2 즉, 1'000'000 / 2 = 500'000개
int zero_area[500'001];
int used_area[4];

// 0 영역 크기 탐색 dfs
int idx = 1;
int area_size = 1;
void dfs(int x, int y, int idx) {
	grid[x][y] = idx;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1 || visited[nx][ny]) continue;

		visited[nx][ny] = true;
		area_size++;
		dfs(nx, ny, idx);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			int cur = str[j] - '0';
			if (cur == 1) grid[i][j] = -1;
			else grid[i][j] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || grid[i][j] == -1) continue;
			area_size = 1;
			visited[i][j] = true;
			dfs(i, j, idx);
			zero_area[idx++] = area_size;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != -1) continue;

			memset(used_area, 0, sizeof(int) * 4);
			
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == -1) continue;

				int cur_area = grid[nx][ny];
				bool used = false;
				for (int l = 0; l < 4; l++) {
					if (used_area[l] == cur_area) {
						used = true;
						break;
					}
				}
				if (used) continue;
				ans_grid[i][j] += zero_area[cur_area];
				used_area[k] = cur_area;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == -1) cout << (ans_grid[i][j] + 1) % 10;
			else cout << 0;
		}
		cout << "\n";
	}
}