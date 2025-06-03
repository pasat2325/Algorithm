#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 1001
using namespace std;
int map[MAX_N][MAX_N] = { 0, };
vector<int> solve(int n, vector<int> w, vector<int>d) {
	queue<int> q;
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0) {
			q.push(i);
			result[i] = w[i];

		}
	}
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[curr][i] == 1) {
				d[i]--;
				result[i] = max(result[i], result[curr] + w[i]);
				if (d[i] == 0) q.push(i);
			}
		}
	}
	return result;
}
int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k; 
		cin >> n >> k;
		vector<int>weight(n + 1);
		vector<int>in_deg(n + 1, 0);

		for (int j = 1; j <= n; j++) cin >> weight[j];
		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
			in_deg[y]++;

		}
		vector<int> res = solve(n, weight, in_deg);
		int z;
		cin >> z;
		cout << res[z] << "\n";
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) map[i][j] = 0;
	}
}