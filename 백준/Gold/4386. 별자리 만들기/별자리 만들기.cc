#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_N = 100;
int parent[MAX_N];

struct Edge {
	double dist;
	int start;
	int end;
};

bool comp(const Edge &a, const Edge &b) {
	return a.dist < b.dist;
}

int find_parent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_parent(parent[x]);
}

void union_set(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x != y) {
		parent[x] = y;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	
	vector<pair<double, double>> stars(n);
	
	for (int i = 0; i < n; i++) {
		cin >> stars[i].first >> stars[i].second;
 	}
	
	vector<Edge> adj;
	adj.reserve(n * n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dx = stars[i].first - stars[j].first;
			double dy = stars[i].second - stars[j].second;
			double dist = hypot(dx, dy);

			adj.push_back({ dist, i ,j });
		}
	}

	sort(adj.begin(), adj.end(), comp);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	double ans = 0;
	int edges_count = 0;

	for (int i = 0; i < adj.size(); i++) {
		double dist = adj[i].dist;
		int start = adj[i].start;
		int end = adj[i].end;

		if (find_parent(start) != find_parent(end)) {
			union_set(start, end);
			ans += dist;
			edges_count += 1;
		}
		if (edges_count == n - 1) break;
	}
	
	printf("%.2f", ans);
	return 0;
}