#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int computer;
int n;
int virus_count = 0; //총 바이러스의 수가 아니라 1로 부터 감염된 수

vector<int> graph[101];
bool visited[101];


void dfs(int num)
{
	visited[num] = true;
	for (int i = 0; i < graph[num].size(); i++)
	{
		int y = graph[num][i];
		if (!visited[y]) {
			dfs(y);
			virus_count++;
		}
	}
}

int main()
{

	cin >> computer >> n;
	for (int i = 0; i < n; i++)
	{
		int s, e;
		cin >> s >> e;

		//간선 연결
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 0; i <= computer; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(1);
	cout << virus_count;
}