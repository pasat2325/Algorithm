#include <iostream>
#include <queue>

using namespace std;


int n, m;
int arr[601][601] = { 0, };
bool visited[601][601];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };

int start_x = 0;
int start_y = 0;
int pcount = 0;

queue<pair<int,int>> q;

void bfs()
{
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;

	while (!q.empty())
	{
		int s = q.front().first;
		int e = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = s + dx[i];
			int next_y = e + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && !visited[next_x][next_y] && arr[next_x][next_y] >= 0)
			{
				if (arr[next_x][next_y] == 1) pcount++;
				visited[next_x][next_y] = true;
				q.push({ next_x,next_y });
			}
		}

	}

}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'X') arr[i][j] = -1;
			else if (s[j] == 'I') {
				start_x = i;
				start_y = j;
			}
			else if (s[j] == 'P') arr[i][j] = 1;
		}
	}

	bfs();

	if (pcount == 0) cout << "TT";
	else cout << pcount;
}