#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int rot[4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<deque<int>> gear(4, deque<int> (8));

	for (int i = 0; i < 4; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++) gear[i][j] = s[j] - '0';
	}

	int t; cin >> t;
	while (t--) {
		int idx, dir; cin >> idx >> dir;
		idx--;

		int rot[4] = { 0, };
		rot[idx] = dir;

		// left
		for (int i = idx - 1; i >= 0; i--) {
			if (gear[i][2] != gear[i + 1][6]) {
				rot[i] = -rot[i + 1];
			}
			else break;
		}

		// right
		for (int i = idx + 1; i < 4; i++) {
			if (gear[i][6] != gear[i - 1][2]) {
				rot[i] = -rot[i - 1];
			}
			else break;
		}
		
		for (int i = 0; i < 4; i++) {
			if (rot[i] == 1) {
				int tmp = gear[i].back();
				gear[i].push_front(tmp);
				gear[i].pop_back();
			}
			else if (rot[i] == -1) {
				int tmp = gear[i].front();
				gear[i].push_back(tmp);
				gear[i].pop_front();
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (gear[i].front() == 1) {
			ans += (1 << i);
		}
	}
	cout << ans;

}