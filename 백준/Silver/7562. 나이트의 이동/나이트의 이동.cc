#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
pair<int, int> nextp[8] = { {2,-1},{2,1},{1,-2},{1,2},{-1,-2},{-1,2},{-2,-1},{-2,1} };
int I;
bool visited[300][300];
int bfs(int curx, int cury, int tarx, int tary, int cnt)
{
	queue<pair<int,pair<int,int>>> q;
	q.push({ cnt,{ curx,cury } });
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int c = q.front().first;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nextx = x + nextp[i].first;
			int nexty = y + nextp[i].second;
			if (nextx >= 0 && nexty >= 0 && nextx < I && nexty < I && !visited[nextx][nexty])
			{
				if (nextx == tarx && nexty == tary) return c + 1;
				visited[nextx][nexty] = true;
				q.push({ c + 1,{ nextx,nexty } });
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int curx, cury, tarx, tary;
		memset(visited, false, sizeof(visited));
		cin >> I >> curx >> cury >> tarx >> tary;
		if (curx == tarx && cury == tary)
		{
			cout << 0 << "\n";
			continue;
		}
		cout << bfs(curx, cury, tarx, tary, 0) << "\n";
	}
}