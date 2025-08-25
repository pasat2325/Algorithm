#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_V = 30'000;
const int MAX_E = 100'000;
int v, e, k;
int candies[MAX_V + 1];
vector<vector<int>> adj(MAX_V + 1);
vector<pair<int, int>> groups;
bool visited[MAX_V + 1];

int group_k, group_c = 0;
void find_group(int n) {
	visited[n] = true;
	group_k++;
	group_c += candies[n];
	for (int i = 0; i < adj[n].size(); i++) {
		if (visited[adj[n][i]]) continue;
		find_group(adj[n][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e >> k;
	for (int i = 1; i <= v; i++) {
		cin >> candies[i];
	}
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= v; i++) {
		if (visited[i]) continue;
		group_k = 0; group_c = 0;
		find_group(i);
		if (group_k < k) groups.push_back({group_k, group_c});
	}
	
	int* dp = (int*)malloc(k * sizeof(int));
	memset(dp, 0, k * sizeof(int));
	for (auto group : groups) {
		int group_k = group.first;
		int group_c = group.second;
		for (int w = k - 1; w >= 0; w--) {
			if (w - group_k < 0) continue;
			dp[w] = max(dp[w], dp[w - group_k] + group_c);
		}
	}
	cout << dp[k - 1] << "\n";
	return 0;
}