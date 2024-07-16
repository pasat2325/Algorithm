#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25] = { 0, };
bool visited[25][25];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;
int bcount;
int acount = 0;

int dfs(int sx, int sy)
{
	visited[sx][sy] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int next_x = sx + dx[i];
		int next_y = sy + dy[i];

		if (next_x < n && next_y < n && next_x >= 0 && next_y >= 0 && map[next_x][next_y] && !visited[next_x][next_y])
		{
			bcount++;
			dfs(next_x, next_y);
		}
	}
	return bcount;
}
int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}
	vector<int> counterVec;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				
				bcount = 1;
				counterVec.push_back(dfs(i, j));
				acount++;
			}
		}
	}

	sort(counterVec.begin(), counterVec.end());
	cout << acount << endl;
	for (int i = 0; i < counterVec.size(); i++)
	{
		cout << counterVec[i] << endl;
	}
}