#include <iostream>
#include <queue>
using namespace std;

const int MAX_P = 1500 * 1500;

int R, C;
char grid[1500][1500];
bool melt[1500][1500];
int parent[MAX_P];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
pair<int, int> L1 = { -1,-1 }, L2;

void make_set(int a) {
	parent[a] = a;
	return;
}

int find_parent(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find_parent(parent[a]);
}

// a는 부모가 된다.
void union_set(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a != b) {
		parent[b] = a;
	}
	return;
}

int change_idx(int i, int j) {
	return C * i + j;
}

int main() {
	cin >> R >> C;
	queue<pair<int, int>> q;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char ch; cin >> ch;

			if (ch == '.') {
				int me_idx = change_idx(i, j);
				make_set(me_idx);

				// 본인 기준 왼쪽, 위쪽만 탐색
				if (i - 1 >= 0 && grid[i - 1][j] == '.') {
					int other_idx = change_idx(i - 1, j);
					union_set(other_idx, me_idx);
				}
				if (j - 1 >= 0 && grid[i][j - 1] == '.') {
					int other_idx = change_idx(i, j - 1);
					union_set(other_idx, me_idx);
				}
			}
			else if (ch == 'L' ) {
				if (L1.first == -1)
					L1 = { i,j };
				else
					L2 = { i,j };

				make_set(change_idx(i, j));
			}

			grid[i][j] = ch;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char ch = grid[i][j];

			if (ch == '.') continue;

			bool w = false;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx >= 0 && ny >= 0 && nx < R && ny < C && (grid[nx][ny] == '.' || grid[nx][ny] == 'L'))
					w = true;
			}
			if (w) {
				q.push({ i,j });
				melt[i][j] = true;
				make_set(change_idx(i, j));
			}
		}
	}
	int cnt = 0;

	while (true) {
		if (find_parent(change_idx(L1.first, L1.second)) == find_parent(change_idx(L2.first, L2.second))) {
			break;
		}

		int it = q.size();
		while (it) {
			int melt_x = q.front().first;
			int melt_y = q.front().second;
			if (grid[melt_x][melt_y] == 'X') grid[melt_x][melt_y] = '.';
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = melt_x + dx[i];
				int ny = melt_y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < R && ny < C && !melt[nx][ny] && grid[nx][ny] == 'X') {
					q.push({ nx,ny });
					melt[nx][ny] = true;
					make_set(change_idx(nx, ny));
				}
				else if (nx >= 0 && ny >= 0 && nx < R && ny < C && (grid[nx][ny] == '.' || grid[nx][ny] == 'L' || grid[nx][ny] == ',')) {
					union_set(change_idx(melt_x, melt_y), change_idx(nx, ny));
				}
			}
			it--;
		}
		cnt++;

	}

	cout << cnt;
}
