#include <iostream>
using namespace std;
int n, m;
char map[1000][1000];
bool visited[1000][1000];
int visited_turn[1000][1000];

bool search(int x, int y, int turn) {
	if (visited[x][y] == true) return false;
	int curr_x = x;
	int curr_y = y;
	while (true) {
		visited[curr_x][curr_y] = true;
		visited_turn[curr_x][curr_y] = turn;
		int nx, ny;
		if (map[curr_x][curr_y] == 'D') {
			nx = curr_x + 1;
			ny = curr_y;
		}
		else if (map[curr_x][curr_y] == 'U') {
			nx = curr_x - 1;
			ny = curr_y;
		}
		else if (map[curr_x][curr_y] == 'L') {
			nx = curr_x;
			ny = curr_y - 1;
		}
		else if (map[curr_x][curr_y] == 'R') {
			nx = curr_x;
			ny = curr_y + 1;
		}
		if (nx >= n || ny >= m || nx < 0 || ny < 0) {
			return true;
		}

		if (visited[nx][ny] == true) {
			if (nx == x && ny == y) {
				return true;
			}
			else if (visited_turn[nx][ny] == turn) return true;
			return false;
		}

		curr_x = nx;
		curr_y = ny;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	int turn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int res = search(i, j, turn);
			ans += res;
			turn++;
		}
	}
	cout << ans;
}