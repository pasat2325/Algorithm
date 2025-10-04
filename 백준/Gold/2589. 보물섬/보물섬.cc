#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e5;
int r, c; 
char grid[50][50];
int dist[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int temp = 0;
int ans = -1;
void bfs(int x, int y) {
	dist[x][y] = 0;
	queue<pair<int,int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c || grid[nx][ny] == 'W')
				continue;
			
			if (dist[nx][ny] <= dist[cx][cy] + 1)
				continue;

			dist[nx][ny] = dist[cx][cy] + 1;
			temp = max(temp, dist[nx][ny]);
			q.push({ nx,ny });
		}
	}
}

void clear_dist() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dist[i][j] = INF;
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'L') {
				clear_dist();
				temp = 0;
				bfs(i, j);
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
}