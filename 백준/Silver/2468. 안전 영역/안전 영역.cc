#include <iostream>
#include <cstring>
using namespace std;
int n;
int map[100][100];
bool visited[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0, -1,1 };

void dfs(int x,int y, int height)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && map[nx][ny] > height)
		{
			dfs(nx, ny, height);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int max_height = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			map[i][j] = x;

			max_height = max_height < x ? x : max_height;
		}
	}


	int result = 0;
	int cnt = 0;
	for (int h = 0; h < max_height; h++)
	{
		memset(visited, false, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] > h && !visited[i][j])
				{
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		result = cnt > result ? cnt : result;
	}

	cout  << result;
}