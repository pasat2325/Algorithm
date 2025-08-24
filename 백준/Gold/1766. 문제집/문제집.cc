#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 32'001;
const int MAX_E = 100'000;

int v, e;
int indeg[MAX_V];
vector<vector<int>> adj(MAX_V);


void topology_sort() {
	priority_queue<int> pq;
	for (int i = 1; i <= v; i++) {
		if (indeg[i] == 0) {
			pq.push(-i);
		}
	}

	while (!pq.empty()) {
		int top = -pq.top();
		pq.pop();

		printf("%d ", top);
		for (int i = 0; i < adj[top].size(); i++) {
			int nx = adj[top][i];
			if (--indeg[nx] == 0) {
				pq.push(-nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		indeg[b]++;
	}
	topology_sort();
}