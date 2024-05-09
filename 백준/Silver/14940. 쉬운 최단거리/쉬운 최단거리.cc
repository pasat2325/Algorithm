#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n, m;
bool visited[1001][1001];
int area[1001][1001];
int dist[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };



void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	dist[x][y] = 0;

	while (!q.empty())
	{
		int s = q.front().first;
		int e = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = s + dx[i];
			int next_y = e + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && !visited[next_x][next_y] && area[next_x][next_y] != 0)
			{
				visited[next_x][next_y] = true;
				dist[next_x][next_y] = dist[s][e] + 1;
				q.push({ next_x,next_y });
			}
		}
	}
}

int main()
{
	int start_x = 0;
	int start_y = 0;
	memset(dist, -1, sizeof(dist));

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			if (num == 2) {
				start_x = i;
				start_y = j;
			}
			else if (num == 0) dist[i][j] = 0;
			area[i][j] = num;
		}
	}

	bfs(start_x, start_y);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}
