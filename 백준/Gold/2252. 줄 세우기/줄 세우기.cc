#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 32001
using namespace std;
vector<vector<int>> map(MAX_N);
vector<int> deg(MAX_N);
vector<int> result;
int n, m;
void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push(i);
			result.push_back(i);
		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < map[curr].size(); i++) {
			int nex = map[curr][i];
			deg[nex]--;

			if (deg[nex] == 0) {
				result.push_back(nex);
				q.push(nex);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x].push_back(y);
		deg[y]++;
	}
	solve();
	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
}