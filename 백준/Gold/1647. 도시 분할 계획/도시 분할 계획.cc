#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100001
#define MAX_M 1000001
using namespace std;
int n, m;
int total_cost;
int max_edge;

vector<pair<int, pair<int, int>>> adj;
int parent[MAX_N];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

bool _union(int x, int y) {
	// 같은 집합이라면 return false
	int rx = find(x);
	int ry = find(y);
	if (rx == ry) return false;
	parent[ry] = rx;
	return true;
}

void mst() {
	for (int i = 0; i < adj.size(); i++) {
		int cur_s = adj[i].second.first;
		int cur_e = adj[i].second.second;

		if (_union(cur_s, cur_e)) {
			total_cost += adj[i].first;
			max_edge = max(max_edge, adj[i].first);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj.push_back({ w,{s,e} });
	}
	sort(adj.begin(), adj.end());
	for (int i = 1; i <= n; i++) parent[i] = i;

	mst();
	cout << total_cost - max_edge << '\n';
}