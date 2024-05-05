#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;

bool visited_dfs[1001];
bool visited_bfs[1001];
vector<int> graph[1001];

void dfs(int x)
{
	visited_dfs[x] = true;
	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited_dfs[y]) dfs(y);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start); // 첫 노드를 queue에 삽입
	visited_bfs[start] = true; // 첫 노드를 방문 처리

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		int x = q.front();
		q.pop();
		cout << x << ' ';
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited_bfs[y]) {
				q.push(y);
				visited_bfs[y] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 0; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";

	bfs(v);
}