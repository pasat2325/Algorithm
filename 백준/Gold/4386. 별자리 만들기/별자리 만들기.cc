#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[100];

struct Edge {
	float dist;
	int start;
	int end;
};

bool comp(Edge a, Edge b) {
	return a.dist < b.dist;
}

int find_parent(int x) {
	if (x == parent[x]) return x;
	else return(find_parent(parent[x]));
}

void union_set(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x != y) {
		parent[x] = y;
	}
}


int main() {
	int n; cin >> n;
	vector<pair<float, float>> stars(n);
	
	for (int i = 0; i < n; i++) {
		float x, y; cin >> x >> y;
		stars[i] = { x,y };
	}
	
	vector<Edge> adj;

	for (int i = 0; i < n; i++) {
		float sx = stars[i].first;
		float sy = stars[i].second;
		for (int j = i + 1; j < n; j++) {
			float nx = stars[j].first;
			float ny = stars[j].second;

			float dx = abs(nx - sx);
			float dy = abs(ny - sy);
			float dist = sqrt(dx * dx + dy * dy);

			adj.push_back({ dist, i ,j });
		}
	}

	sort(adj.begin(), adj.end(), comp);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	float ans = 0;
	for (int i = 0; i < adj.size(); i++) {
		float dist = adj[i].dist;
		int start = adj[i].start;
		int end = adj[i].end;

		if (find_parent(start) == find_parent(end)) {
			continue;
		}

		union_set(start, end);
		ans += dist;
	}
	
	printf("%.2f", ans);
	
}