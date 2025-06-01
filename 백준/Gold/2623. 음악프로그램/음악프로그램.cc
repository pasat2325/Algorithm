#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[1001][1001];
int in_deg[1001];
int n, m;
vector<int> bfs() {
	vector<int> result;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!in_deg[i]) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		result.push_back(curr);
		for (int i = 1; i <= n; i++) {
			if (map[curr][i] == 1) {
				in_deg[i]--;
				if (in_deg[i] == 0) q.push(i);
			}

		}
	}
	return result;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int prev;
		cin >> prev;
		for (int j = 1; j < x; j++) {
			int curr;
			cin >> curr;
			if (!map[prev][curr]) {
				map[prev][curr] = 1;
				in_deg[curr]++;
			}
			prev = curr;
		}
	}
	vector<int> result = bfs();
	if (result.size() == n) {
		for (auto i : result) cout << i << "\n";
	}
	else cout << 0;
}