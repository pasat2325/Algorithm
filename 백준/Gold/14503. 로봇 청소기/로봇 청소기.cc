#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>>map(50, vector<int>(50));
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m;

int solve(int x, int y, int d) {
	int res = 0;
	int curd = d;
	int curx = x;
	int cury = y;
	while (true) {
		if (map[curx][cury] == 0) {
			map[curx][cury] = 2;
			res++;
		}
		bool need_clean = false;
		for (int i = 0; i < 4; i++) {
			int nx;
			int ny;
			if (curd == 0) {
				nx = curx;
				ny = cury - 1;
			}
			else if (curd == 1) {
				nx = curx - 1;
				ny = cury;
			}
			else if (curd == 2) {
				nx = curx;
				ny = cury + 1;
			}
			else {
				nx = curx + 1;
				ny = cury;
			}
			curd = (curd + 3) % 4;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 0) {
				curx = nx;
				cury = ny;
				need_clean = true;
				break;
			}
		}
		if (need_clean) continue;

		int nx;
		int ny;
		if (curd == 0) {
			nx = curx + 1;
			ny = cury;
		}
		else if (curd == 1) {
			nx = curx;
			ny = cury - 1;
		}
		else if (curd == 2) {
			nx = curx - 1;
			ny = cury;
		}
		else {
			nx = curx;
			ny = cury + 1;
		}
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 1 ) {
			return res;
		}
		curx = nx;
		cury = ny;
	}
}
int main() {
	cin >> n >> m;
	int r, c, d; cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = solve(r, c, d);
	cout << ans;
}