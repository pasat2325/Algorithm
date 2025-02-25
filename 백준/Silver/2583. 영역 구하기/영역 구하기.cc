#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int m, n, k;
int map[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[100][100];
int area = 0;
void dfs(int startx,int starty)
{
	visited[startx][starty] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = startx + dx[i];
		int ny = starty + dy[i];
		if (nx >= 0 && ny >= 0 && nx < m && ny < n && !map[nx][ny] && !visited[nx][ny])
		{
			area++;
			dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		for (int j = m - x2; j < m - x1; j++)
		{
			for (int k = y1; k < y2; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	int areaCnt = 0;
	vector<int>areas;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[i][j] && !visited[i][j])
			{
				area = 1;
				areaCnt++;
				dfs(i, j);
				areas.push_back(area);
			}
		}
	}
	sort(areas.begin(), areas.end());
	cout << areaCnt <<"\n";
	for (auto i : areas) cout << i << " ";
}