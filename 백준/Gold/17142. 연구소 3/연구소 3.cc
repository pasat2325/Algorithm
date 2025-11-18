/*
* 
* 조합으로 바이러스들 다중점 BFS
* 
*/

#include <iostream>
#include <queue>
using namespace std;
int N, M;
int grid[50][50];
int visited[50][50];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int,int>> v;
queue<pair<int, int>> q;


void bfs() {
	while (1) {
		int len = q.size();
		if (len == 0) break;

		while (len--) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				if (grid[nx][ny] == 1) continue;

				if (visited[nx][ny] <= visited[cx][cy] + 1) continue;
				
				visited[nx][ny] = visited[cx][cy] + 1;
				q.push({ nx,ny });
			}
		}
	}
}


int main() {
	cin >> N >> M;

	int vcnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) { 
				vcnt++;
				v.push_back({ i,j }); }
		}
	}
	
	int res = 3000;
	for (int i = 1; i < (1 << vcnt); i++) {
		int bitc = 0;
		for (int j = 0; j < vcnt; j++) {
			if (i & (1 << j)) bitc++;
		}

		if (bitc != M) continue;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 3000;
				if (grid[i][j] == 1 ) visited[i][j] = -1;
			}
		}

		for (int j = 0; j < vcnt; j++) {
			if (i & (1 << j)) {
				q.push({ v[j]});
				visited[v[j].first][v[j].second] = 0;
			}
		}
		bfs();

		int tmp = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (grid[i][j] != 0) continue;
				tmp = max(visited[i][j], tmp);
			}
		}

		res = min(res, tmp);
	}
	if (res == 3000) cout << -1;
	else cout << res;

	
}
