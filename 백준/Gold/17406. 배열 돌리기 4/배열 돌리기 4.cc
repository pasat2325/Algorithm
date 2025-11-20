#include <iostream>
#include <vector>
using namespace std;


int N, M, C;
struct cmd {
	int r;
	int c;
	int s;
};

vector<cmd> commands(6);
int ans = 1e9;


void printg(const int grid[50][50]) {
	cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

void rotate_grid(cmd cc, const int grid[50][50], int after[50][50]) {
	int r = cc.r;
	int c = cc.c;
	int s = cc.s;

	int ltx = r - s; int lty = c - s;
	int rbx = r + s; int rby = c + s;

	int len = 2 * s;
	while (len > 0) {
		for (int i = 0; i < 4; i++) {
			// hor
			if (i == 0) {
				for (int j = 1; j <= len; j++) {
					after[ltx][lty + j] = grid[ltx][lty + j - 1];
				}
			}
			else if (i == 1) {
				for (int j = 1; j <= len; j++) {
					after[ltx + j][rby] = grid[ltx + j - 1][rby];
				}
			}
			else if (i == 2) {
				for (int j = 1; j <= len; j++) {
					after[rbx][rby - j] = grid[rbx][rby - j + 1];
				}
			}
			else {
				for (int j = 1; j <= len; j++) {
					after[rbx - j][lty] = grid[rbx - j + 1][lty];
				}
			}
		}
		len -= 2;
		ltx++, lty++;
		rbx--; rby--;
	}
}

int cal_val(const int grid[50][50]) {
	int ret = 1e9;
	for (int i = 0; i < N; i++) {
		int row = 0;
		for (int j = 0; j < M; j++) {
			row += grid[i][j];
		}
		ret = min(ret, row);
	}
	return ret;
}

void solve(int depth, const int grid[50][50], int used) {
	if (depth == C) {
		int val = cal_val(grid);
		ans = min(ans, val);
		return;
	}

	for (int i = 0; i < C; i++) {
		if ((1 << i) & used) continue;
		cmd curc = commands[i];
		int tmp[50][50];
		copy(&grid[0][0], &grid[0][0] + 50* 50, &tmp[0][0]);
		//printg(tmp);
		rotate_grid(curc, grid, tmp);
		//printg(tmp);
		solve(depth + 1, tmp, ((1 << i) | used));
	}
	return;
}


int main() {
	int grid[50][50];
	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < C; i++) {
		int r, c, s; cin >> r >> c >> s;
		r--; c--;
		commands[i] = { r,c,s };
	}

	solve(0, grid, 0);

	cout << ans;
}