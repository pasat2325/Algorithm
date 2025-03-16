#include <iostream>
#include <vector>
#define INF 1e18
#define MAX_V 501
using namespace std;
int v, e;
vector<pair<int, int>> adj[MAX_V];

vector<long long> bellmanFord(int src) {
	vector<long long> upper(v + 1,INF);
	upper[src] = 0;
	// v-1번 순회한다.
	for (int iter = 0; iter < v - 1; iter++) {
		for (int here = 1; here <= v; here++) {
			if (upper[here] == INF) continue;
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				// (here, there) 간선을 따라 완화를 시도한다.
				upper[there] = min(upper[there], upper[here] + cost);
			}
		}
	}
	// 음수 사이클의 존재 여부를 확인한다.
	for (int here = 1; here <= v; here++) {
		if (upper[here] == INF) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			// 완화가 성공한다면 here는 음수 사이클에 들어있다.
			if (upper[here] + cost < upper[there]) {
				return vector<long long>();
			}
		}
	}
	return upper;
}


int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({ e,w });
	}
	vector<long long> result = bellmanFord(1);
	if (result.empty()) cout << -1 << "\n";
	else {
		for (int i = 2; i <= v; i++) {
			if (result[i] == INF) cout << -1 << "\n";
			else cout << result[i] << "\n";
		}
	}
	return 0;
}