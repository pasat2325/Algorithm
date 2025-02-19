#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int check_remaining(int n, int m, vector<vector<int>>& map)
{
	int cheese = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1) cheese++;
		}
	}
	return cheese;
}

void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>> &rv)
{
	
	rv[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < map.size() && ny < map[0].size())
		{
			if (map[nx][ny] == 0 && !rv[nx][ny])
			{
				dfs(nx, ny, map, rv);
			}
			else
			{
				map[nx][ny] = 0;
				rv[nx][ny] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			map[i][j] = x;
		}
	}

	int cnt = 0;
	int prev;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int cheese = check_remaining(n, m, map);
			prev = cheese == 0 ? prev:cheese;

			if (cheese != 0)
			{
				cnt++;
				vector<vector<bool>> rv(n, vector<bool>(m));
				dfs(0, 0, map, rv);
			}
			else
			{
				break;
			}
		}
	}
	cout << cnt << "\n" << prev;

}