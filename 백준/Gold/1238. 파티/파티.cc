#include <iostream>
#include <queue>
#include <vector>
using namespace std;


const static int maxv = 1000;
const static int INF = 1e9;
vector<pair<int, int>> graph[1001];

int v, e, target; // 정점, 엣지, 목표 도시

vector<int> dijk(int start)
{
	vector<int> dist(v + 1, INF);
	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty())
	{
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_dist = cur_dist + graph[cur_node][i].second;

			if (next_dist < dist[next_node])
			{
				dist[next_node] = next_dist;
				pq.push({ -next_dist, next_node });
			}
		}
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e >> target;
	
	for (int i = 0; i < e; i++)
	{
		int from, to, weight;
		cin >> from >> to >>  weight;

		graph[from].push_back({ to, weight });
	}

	int max_dist = 0;
	vector<int> return_dist = dijk(target);
	for (int i = 1; i <= v; i++)
	{
		vector<int> going_dist = dijk(i);
		int dist = going_dist[target] + return_dist[i];
		max_dist = (max_dist < dist) ? dist : max_dist;
	}
	cout << max_dist;
}