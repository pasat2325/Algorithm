#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
int map[8][8];
int tempMap[8][8];
vector<pair<int, int>> v;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int safeCnt;
int ans;

void copyMap() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			tempMap[i][j] = map[i][j];
		}
}

void bfs(queue<pair<int, int>> q) {
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

void solve(int now, int depth, queue<pair<int,int>> q) {
	if (depth == 3) {
		copyMap();
		bfs(q);
		safeCnt = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (tempMap[i][j] == 0) safeCnt++;
			}

		ans = safeCnt > ans ? safeCnt : ans;
		return;
	}

	for (int i = now; i < v.size(); i++) {
		map[v[i].first][v[i].second] = 1;
		solve(i + 1, depth + 1, q);
		map[v[i].first][v[i].second] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				q.push({ i,j });
			else if (map[i][j] == 0) v.push_back({ i,j });

		}

	
	solve(0, 0, q);
	cout << ans;
}