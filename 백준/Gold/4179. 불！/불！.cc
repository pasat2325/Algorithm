#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int INF = 1e8;
int R, C;
char grid[1000][1000];
int dist[1000][1000];
queue<pair<int, int>> q;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
	int jsx, jsy;
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
			dist[i][j] = INF;
			if (grid[i][j] == 'J') {
				jsx = i;
				jsy = j;
			}
			else if (grid[i][j] == 'F') {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == '#')
				continue;

			if (dist[nx][ny] <= dist[cx][cy] + 1)
				continue;

			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}

	dist[jsx][jsy] = 0;
	q.push({ jsx,jsy });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		if (cx == 0 || cy == 0 || cx == R - 1 || cy == C - 1) {
			cout << dist[cx][cy] + 1;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || grid[nx][ny] == '#' || grid[nx][ny] == 'F')
				continue;

			if (dist[nx][ny] - dist[cx][cy] < 2) continue;
			
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
	/*
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}*/

}