#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, l; cin >> n >> l;
	priority_queue<pair<int, int>> holes;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		holes.push({ -x, -y });
	}

	int prev = -1;
	int cnt = 0;

	while (!holes.empty()) {
		int hole_x = -holes.top().first;
		int hole_y = -holes.top().second;

		if (prev > hole_x) {
			if (prev < hole_y) {
				cnt += 1;
				prev += l;
			}
			else {
				holes.pop();
			}
		}
		else if (prev <= hole_x) {
			cnt += 1;
			prev = hole_x + l;
		}
	}
	cout << cnt;
}