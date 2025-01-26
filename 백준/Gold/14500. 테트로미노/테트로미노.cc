#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[500][500];
bool visited[500][500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


// ㅗ을 제외한 모든 테트로미노로 구해지는 각각의 합은 depth 4의 dfs를 통해 구할 수 있다. 
void dfs(int curx, int cury, int depth, int val)
{
	if (depth == 4)
	{
		ans = max(ans, val);
		return;
	}

	visited[curx][cury] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = curx + dx[i];
		int ny = cury + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny])
		{
			dfs(nx, ny, depth + 1, val + map[nx][ny]);
		}
	}
	visited[curx][cury] = false;
}

// ㅗ ㅏ ㅓ ㅜ 
int extra(int curx, int cury)
{
	int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;

	if (curx - 1 >= 0 && cury + 1 < m && cury - 1 >= 0) temp1 = map[curx][cury] + map[curx][cury - 1] + map[curx][cury + 1] + map[curx - 1][cury];

	if (curx - 1 >= 0 && cury + 1 < m && curx + 1 < n) temp2 = map[curx][cury] + map[curx][cury + 1] + map[curx - 1][cury] + map[curx + 1][cury];

	if (curx + 1 < n && cury + 1 < m && cury - 1 >= 0) temp3 = map[curx][cury] + map[curx][cury - 1] + map[curx][cury + 1] + map[curx + 1][cury];
	
	if (curx - 1 >= 0 && cury - 1 >= 0 && curx + 1 < n) temp4 = map[curx][cury] + map[curx - 1][cury] + map[curx + 1][cury] + map[curx][cury - 1];

	temp1 = (temp1 > temp2) ? temp1 : temp2;
	temp3 = (temp3 > temp4) ? temp3 : temp4;
	int val = (temp1 > temp3) ? temp1 : temp3;
	return val;
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

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, 1, map[i][j]);
			int tempex = extra(i, j);
			int temp = (ans < tempex) ? tempex : ans;
			max = (max < temp) ? temp : max;

		}
	}
	cout << max;
}