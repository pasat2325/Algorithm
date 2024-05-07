#include <iostream>
#include <queue>
#include <string>


using namespace std;

int N, M;
int maze[101][101];
int visited[101][101];
int dist[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs(int s, int e)
{
	visited[s][e] = 1;
	q.push(make_pair(s, e));
	dist[s][e]++;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && !visited[next_x][next_y] && maze[next_x][next_y])
			{
				visited[next_x][next_y] = 1;
				q.push(make_pair(next_x, next_y));
				dist[next_x][next_y] = dist[x][y] + 1;
			}
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;

		for (int j = 0; j < M; j++)
		{
			maze[i][j] = row[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[N - 1][M - 1];
}