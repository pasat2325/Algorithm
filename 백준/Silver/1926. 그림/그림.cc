#include <iostream>

using namespace std;

int map[500][500];
int visited[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m; // 가로 세로

int dfs(int x, int y, int extent)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 1 && !visited[nx][ny])
		{

			extent = dfs(nx, ny, extent + 1);
		}
	}
	return extent;
}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			map[i][j] = x;
		}
	}

	int count = 0;
	int max_extent = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(map[i][j] == 1 && !visited[i][j])
			{
				count++;
				int extent = dfs(i, j, 1);
				max_extent = extent > max_extent ? extent : max_extent;
			}
		}
	}
	cout << count << "\n" << max_extent;
}