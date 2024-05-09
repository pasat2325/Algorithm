#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[1000];
vector<int> v[1001];

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < v[start].size(); i++)
	{
		int next = v[start][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main()
{
	int n, m, count = 0;
	cin >> n >> m;

	
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;

		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	
	for (int i = 0; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (!visited[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count;
}