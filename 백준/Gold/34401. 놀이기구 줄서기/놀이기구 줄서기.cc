#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
	int n, p, k;
	cin >> n >> p >> k;

	vector<pair<int, int>> groups;
	for (int i = 0; i < n; i++) {
		int t, a; cin >> t >> a;
		groups.push_back({ t,a });
	}

	sort(groups.begin(), groups.end());

	queue<pair<int, int>> q[6];
	for (auto g : groups) {
		q[g.second].push(g);
	}

	long long total_wait = 0;
	int comp = 0;
	int time = 0;

	while (comp < n) {
		int seat = k;
		while (seat > 0) {
			int cs = -1;
			int ct = INT_MAX;

			for (int i = 1; i <= seat; i++) {
				if (!q[i].empty()) {
					auto g = q[i].front();
					if (g.first <= time) {
						if (g.first < ct) {
							ct = g.first;
							cs = g.second;
						}
					}
				}
			}

			if (cs == -1) {
				break;
			}

			auto g = q[cs].front();
			q[cs].pop();

			total_wait += (time - g.first);
			seat -= cs;
			comp += 1;
		}

		time += p;
	}
	cout << total_wait;
}