#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int visited[100001] = {0,};
int nextn = 0;

int bfs(int s, int e)
{
	q.push(s);
	visited[s] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 3; i++)
		{
			if (i == 0) nextn = cur + 1;
			else if (i == 1) nextn = cur - 1;
			else if (i == 2) nextn = cur * 2;
			

			if (nextn >= 0 && nextn <= 100001 && visited[nextn] == 0) {
				visited[nextn] = visited[cur] + 1;
				if (nextn == e) return visited[nextn];
				q.push(nextn);
			}
		}
	}
	return visited[nextn];
}



int main()
{
	int s, e;
	cin >> s >> e;
	if (s == e) cout << 0;
	else
	cout << bfs(s,e) - 1;

	
}