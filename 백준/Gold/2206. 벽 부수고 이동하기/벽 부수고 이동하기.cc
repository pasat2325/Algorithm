/*
구조체에 좌표와 벽 파괴 여부를 저장해서 queue에 삽입.
특정 좌표의 벽을 부수고 이동하면 벽 파괴 여부를 true로 바꾼다.
그 특정 좌표로 부터 파생된 경로부터는 더이상 벽을 부수고 이동할 수 없음을 나타낸다.

탐색 중 처음으로 벽을 만나면 무조건 부수며 이동.
더 이상 벽을 부술 수 없는데, 벽에 둘러 쌓이면 목표에 도달이 불가능하다.

벽 파괴 여부가 true일 때 방문하는 좌표들은 벽 파괴 여부가 false라면 방문이 가능해야한다.
벽을 부수지 못해서 넘어가지 못하는 경로를 막으면 안되기 때문이다.
*/
#include <queue>
#include <iostream>
using namespace std;


struct point {
	int x;
	int y;
	int cnt = 1;
	bool broke = false;
};

int n, m; // 가로,세로
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0, 1, -1 };
int map[1000][1000];
bool visited[1000][1000];

int bfs(int startx, int starty)
{
	queue<struct point> q;
	q.push({ startx,starty });
	
	while (!q.empty())
	{
		int curx = q.front().x;
		int cury = q.front().y;
		int cnt = q.front().cnt;
		bool broke = q.front().broke;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			/*
			벽을 이미 한번 부순 경우 일반적인 bfs를 수행한다. 이때 벽을 한번 부순채로 방문했음을 표시하기
			위해서 해당 좌표의 값을 -1로 변경한다.
			*/

			if (broke && nx >= 0 && ny >= 0 &&  nx < n && ny < m && !visited[nx][ny] && map[nx][ny] == 0)
			{
				if (nx == n - 1 && ny == m - 1) return ++cnt;
				map[nx][ny] = -1;
				visited[nx][ny] = true;
				q.push({ nx, ny, cnt + 1, broke });
				
			}

			/*
			벽을 한번도 부수지 않은 경우 visited가 true라도 map[nx][ny] = -1이라면 방문이 가능하다.
			*/
			else if (!broke && nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (nx == n - 1 && ny == m - 1) return ++cnt;
				else if (map[nx][ny] == -1)
				{
					map[nx][ny] = -2;
					q.push({ nx,ny,cnt + 1,broke });
				}
				else if (map[nx][ny] == 1)
				{
					q.push({ nx,ny,cnt + 1,!broke });
				}
				else if (!visited[nx][ny] && map[nx][ny] == 0)
				{
					q.push({ nx,ny,cnt + 1,broke });
					visited[nx][ny] = true;
				}
			}
		}
	}
	return -1;
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
			map[i][j] = s[j] - '0';
		}
	}
	if (n == 1 && m == 1) cout << 1;
	else cout <<bfs(0, 0);
}