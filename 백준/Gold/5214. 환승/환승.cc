#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 100'000 + 1'000;

int n, k, m; // 역의 수, 연결하는 역의 수, 하이퍼튜브의 개수
vector<int> adj[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N];

void bfs(int s) {
	visited[s] = true;
	queue<int> q;
	q.push(s);
	dist[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int hc = adj[x][i];
			// 이미 방문했던 하이퍼 큐브는 다시 방문할 필요가 없다. 최단 경로가 될 수 없기 때문이다.
			if (visited[hc])
				continue;

			visited[hc] = true;

			for (int j = 0; j < adj[hc].size(); j++) {
				int nx = adj[hc][j];

				if (visited[nx])
					continue;
				
				visited[nx] = true;

				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			adj[x].push_back(n + i);
			adj[n + i].push_back(x);
		}
	}
	bfs(1);
	if (dist[n] == 0) cout << -1;
	else cout << dist[n];
}