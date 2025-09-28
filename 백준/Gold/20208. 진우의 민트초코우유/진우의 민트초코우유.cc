#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>>grid(10, vector<int>(10));
vector<pair<int, int>> milks;
vector<vector<bool>> eaten_milk(10, vector<bool>(10));

int house_pos_x, house_pos_y;
int N, M, H;

int ans = 0;
void solve(int curx, int cury, int hp, int cnt) {
	int dist_to_home = abs(curx - house_pos_x) + abs(cury - house_pos_y);
	if (dist_to_home <= hp) {
		ans = max(cnt, ans);
	}

	for (int i = 0; i < milks.size(); i++) {
		int milkx = milks[i].first;
		int milky = milks[i].second;

		if (eaten_milk[milkx][milky]) continue;

		int dist = abs(curx - milkx) + abs(cury - milky);

		if (dist > hp) continue;

		eaten_milk[milkx][milky] = true;
		solve(milkx, milky, hp - dist + H, cnt + 1);
		eaten_milk[milkx][milky] = false;
	}
}


int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int v; cin >> v;
			if (v == 1) {
				house_pos_x = i;
				house_pos_y = j;
 			}
			grid[i][j] = v;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (grid[i][j] == 2) {
				milks.push_back({ i,j });
			}
		}
	}
	solve(house_pos_x, house_pos_y, M, 0);
	cout << ans;
}