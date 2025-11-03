#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool visited[101][101];
char grid[11][11];

pair<int, int> hole, init_red, init_blue;

int change(int x, int y) {
	return m * x + y;
}
pair<int, int> xchange(int z) {
	return { z / m, z % m };
}

char who_first(int redx, int redy, int bluex, int bluey, int dir) {
	// 왼쪽으로 기울일 때는 더 왼쪽에 있는 구슬이 먼저 이동한다.
	if (dir == 1) {
		return redy <= bluey ? 'R' : 'B';
	}
	else if (dir == 2) {
		return redy >= bluey ? 'R' : 'B';
	}
	else if (dir == 3) {
		return redx <= bluex ? 'R' : 'B';
	}
	else return redx >= bluex ? 'R' : 'B';
}

// 1: left, 2: right, 3: up, 4: down
pair<int, int> move(int x, int y, int dir, int otherx, int othery) {

	pair<int, int> s;
	if (dir == 1) {
		s = { 0, -1 };
	}
	else if (dir == 2) {
		s = { 0, 1 };
	}
	else if (dir == 3) {
		s = { -1 , 0 };
	}
	else {
		s = { 1, 0 };
	}

	int nx = x + s.first;
	int ny = y + s.second;

	while (true) {
		if (grid[nx][ny] == '#' || (nx == otherx && ny == othery)) {
			return { x,y };
		}
		else if (grid[nx][ny] == 'O') {
			return { nx, ny };
		}

		x = nx; y = ny;
		nx = x + s.first; ny = y + s.second;
	}
}


int bfs(int redx, int redy, int bluex, int bluey) {
	queue<pair<pair<int, int>, int>> q;
	int redp = change(redx, redy);
	int bluep = change(bluex, bluey);
	q.push({{ redp, bluep }, 0});
	visited[redp][bluep] = true;

	while (!q.empty()) {
		int cur_redp = q.front().first.first;
		int cur_bluep = q.front().first.second;
		int cur_cnt = q.front().second;
		q.pop();

		pair<int, int> redxy = xchange(cur_redp);
		pair<int, int> bluexy = xchange(cur_bluep);

		if (redxy.first == hole.first && redxy.second == hole.second) {
			return cur_cnt;
		}

		for (int i = 1; i <= 4; i++) {
			pair<int, int> red_nt;
			pair<int, int> blue_nt;
			if (who_first(redxy.first, redxy.second, bluexy.first, bluexy.second, i) == 'R') {
				red_nt = move(redxy.first, redxy.second, i, bluexy.first, bluexy.second);
				if (red_nt.first == hole.first && red_nt.second == hole.second) {
					blue_nt = move(bluexy.first, bluexy.second, i, 0, 0);
				}
				else blue_nt = move(bluexy.first, bluexy.second, i, red_nt.first, red_nt.second);

				if (blue_nt.first == hole.first && blue_nt.second == hole.second) continue;
			}
			else {
				blue_nt = move(bluexy.first, bluexy.second, i, redxy.first, redxy.second);
				//파란구슬이 먼저 빠졌다.
				if (blue_nt.first == hole.first && blue_nt.second == hole.second) {
					continue;
				}
				red_nt = move(redxy.first, redxy.second, i, blue_nt.first, blue_nt.second);
			}
			int nextredp = change(red_nt.first, red_nt.second);
			int nextbluep = change(blue_nt.first, blue_nt.second);

			if (visited[nextredp][nextbluep]) {
				continue;
			}

			visited[nextredp][nextbluep] = true;
			q.push({{ nextredp, nextbluep }, cur_cnt + 1});
		}
	}
	return  -1;
}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'O') hole = { i,j };
			else if (grid[i][j] == 'R') {
				init_red = { i,j };
				grid[i][j] = '.';
			}
			else if (grid[i][j] == 'B') {
				init_blue = { i,j };
				grid[i][j] = '.';
			}
		}
	}
	int result = bfs(init_red.first, init_red.second, init_blue.first, init_blue.second);

	if (result > 10) cout << -1;
	else cout << result;
}
