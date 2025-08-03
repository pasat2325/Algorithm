#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 2000
using namespace std;
int n, r;
bool result = false;
vector<vector<int>> adj(MAX_N);
bool visited[MAX_N];
void dfs(int x, int depth) {
	if (depth >= 5) {
		result = true;
		return;
	}
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (visited[y]) continue;
		dfs(y, depth + 1);
		visited[y] = false;
	}
}
int main() {
	cin >> n >> r;
	for (int i = 0; i < r; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (result) break;
		memset(visited, false, sizeof(visited));
		dfs(i, 1);
	}
	if (result) cout << 1;
	else cout << 0;
}