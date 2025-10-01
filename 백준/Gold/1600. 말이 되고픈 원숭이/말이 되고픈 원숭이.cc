#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int k, w, h;
vector<vector<int>> M(200, vector<int>(200));
bool visited[200][200][31];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int hdx[8] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int hdy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };

using Node = tuple<int, int, int>;

int bfs(int x, int y) {
	queue<pair<Node, int>> q;
	q.push({{ x,y,k }, 0});
	visited[x][y][k] = true;
	
	while (!q.empty()) {
		Node cur = q.front().first;
		int cx = get<0>(cur);
		int cy = get<1>(cur);
		int ck = get<2>(cur);
		int cc = q.front().second;

		if (cx == h - 1 && cy == w - 1) {
			return cc;
		}
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny][ck] || M[nx][ny] == 1)
				continue;

			visited[nx][ny][ck] = true;
			q.push({{ nx,ny,ck }, cc + 1});
		}

		if (!ck)
			continue;

		for (int i = 0; i < 8; i++) {
			int nx = cx + hdx[i];
			int ny = cy + hdy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny][ck - 1] || M[nx][ny] == 1)
				continue;

			visited[nx][ny][ck - 1] = true;
			q.push({ { nx,ny, ck - 1 }, cc + 1 });

		}
	}
	return  -1;
}


int main() {
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> M[i][j];
		}
	}

	int ans = bfs(0, 0);
	cout << ans;
}