#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 1001
using namespace std;
int n, m;
double total_cost;
vector<pair<double, pair<int, int>>> adj;
vector<pair<int, int>> pre;
vector<pair<int, int>> coords;
int parent[MAX_N];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool _union(int s, int e) {
	int rs = find(s);
	int re = find(e);
	if (rs == re) return false;
	parent[re] = rs;
	return true;
}

void mst() {
	for (int i = 0; i < pre.size(); i++) {
		int s = pre[i].first;
		int e = pre[i].second;
		_union(s, e);
	}

	for (int i = 0; i < adj.size(); i++) {
		int x = adj[i].second.first;
		int y = adj[i].second.second;
		double dist = adj[i].first;
		if (_union(x, y)) {
			total_cost += dist;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coords.push_back({ x,y });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2));
			adj.push_back({ dist,{i + 1, j + 1} });
		}
	}
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		pre.push_back({ s,e });
	}
	for (int i = 1; i <= n; i++) parent[i] = i;
	sort(adj.begin(), adj.end());

	mst();
	printf("%.2f", total_cost);
}