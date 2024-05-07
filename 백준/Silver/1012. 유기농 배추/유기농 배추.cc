#include <iostream>
#include <cstring>

using namespace std;

int m, n, k;

bool area[51][51];
bool check[51][51];
int dx[4] = {0,0,1,-1};
int dy[4] = { 1,-1,0,0 };

bool dfs(int y, int x)
{
	if (check[y][x]) return false;
	check[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i]; //동서남북
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && area[next_y][next_x])
			dfs(next_y, next_x);
	}
	return true;
}

int main()
{
	int t; // test-case
	cin >> t;

	
	for (int i = 0; i < t; i++)
	{
		memset(area, 0, sizeof(area));
		memset(check, 0, sizeof(check));
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;

			area[y][x] = 1;
		}

		int bug = 0;

		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (area[j][k] && !check[j][k])
				{
					if (dfs(j, k)) bug++;
				}
			}
		}
		cout << bug << "\n";
	}


}
