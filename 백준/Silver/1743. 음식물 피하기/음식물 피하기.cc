#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;


int g[101][101] = { 0, }; // 격자
bool visited[101][101];
int n, m, k;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int dfs(int startx, int starty) {
	visited[startx][starty] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nextx = startx + dx[i];
		int nexty = starty + dy[i];

		if (g[nextx][nexty] == 1 && !visited[nextx][nexty] && nextx <= n && nextx >= 1 && nexty <= m && nexty >= 1)
			ret += dfs(nextx, nexty);
	}
	return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		g[r][c] = 1;
	}

	memset(visited, false, sizeof(visited));

	int maxv = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 1 && !visited[i][j]) {
				int temp = dfs(i, j);
				maxv = max(temp, maxv);
			}
		}
	}
	cout << maxv;
}