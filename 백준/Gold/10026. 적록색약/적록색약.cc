#include <iostream>
#include <string.h>
using namespace std;

int N;
int arr[100][100];
bool visited[100][100];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int count_area1 = 0;
int count_area2 = 0;

void dfs(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visited[next_x][next_y] && arr[x][y] == arr[next_x][next_y])
		{
			dfs(next_x, next_y);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < N; j++)
		{
			//R = 0, G = 1, B = 2

			if (s[j] == 'R') arr[i][j] = 0;
			else if (s[j] == 'G') arr[i][j] = 1;
			else arr[i][j] = 2;
		}
	}

	
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) { 
				dfs(i, j);
				count_area1++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) {
				dfs(i, j);
				count_area2++;
			}
		}
	}

	cout << count_area1 << " " << count_area2;
}