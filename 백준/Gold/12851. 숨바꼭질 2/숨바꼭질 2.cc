#include <iostream>
#include <queue>
#include <climits>
#define MAX_D 100001
using namespace std;
int st, ed;
int min_time = INT_MAX, cnt;
int dw[2] = { 1,-1 };
bool map[MAX_D];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ st, 0 });
	map[st] = true;
	while (!q.empty()) {
		int curr = q.front().first;
		int curr_time = q.front().second;
		map[curr] = true;
		q.pop();
		if (curr_time >= min_time) continue;

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 2) nx = curr * 2;
			else nx = curr + dw[i];
			
			if (nx == ed) {
				if (min_time > curr_time + 1) {
					min_time = curr_time + 1;
					cnt = 1;
				}
				else if (min_time == curr_time + 1) cnt++;
				continue;
			}

			if (nx >= 0 && nx < MAX_D && !map[nx]) {
				q.push({ nx,curr_time + 1 });
			}
		}
	}
}
int main() {
	cin >> st >> ed;
	if (st == ed) cout << 0 << "\n" << 1;
	else {
		bfs();
		cout << min_time << "\n" << cnt;
	}
}