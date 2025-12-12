/*
길의 가로등을 켜두면 하루에 길의 미터 수만큼 돈이 들어간다.

모든 집 쌍 사이에는 서로 연결된 경로가 존재해야한다.

즉, 최소 신장 트리 구성하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 2e5;

int parent[MAX_V];

struct Edge {
	int dist;
	int x;
	int y;
};

bool comp(const Edge& a, const Edge& b) {
	return a.dist < b.dist;
}

int find_root(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find_root(parent[x]);
}

void union_set(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if (x != y)
		parent[x] = y;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	while(1) {
		int v, e;
		cin >> v >> e;
		if (!v && !e) break;

		vector<Edge> edges;

		int total = 0;
		for (int i = 0; i < e; i++) {
			int x, y, d;
			cin >> x >> y >> d;
			edges.push_back({ d,x,y });
			total += d;
		}

		for (int i = 0; i < v; i++) {
			parent[i] = i;
		}

		sort(edges.begin(), edges.end(), comp);

		int dd = 0;
		int edges_count = 0;

		for (int i = 0; i < e; i++) {
			int x, y, d;
			x = edges[i].x;
			y = edges[i].y;
			d = edges[i].dist;

			if (find_root(x) != find_root(y)) {
				union_set(x, y);
				dd += d;
				edges_count++;
			}

			if (edges_count == v - 1) break;
		}
		cout << total - dd << "\n";
	}
}