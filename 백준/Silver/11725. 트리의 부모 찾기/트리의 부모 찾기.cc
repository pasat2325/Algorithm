#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxNum = 100001;

queue<int> q;
vector<int> v[maxNum];
bool visit[maxNum];
int parent[maxNum];
int t, a, b;

void solve()
{
	visit[1] = true;

	for (auto i : v[1])
	{
		q.push(i);
		visit[i] = true;
		parent[i] = 1;
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : v[cur])
		{
			if (!visit[i]) {
				q.push(i);
				visit[i] = true;
				parent[i] = cur;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> t;

	for (int i = 0; i < t - 1; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	for (int i = 2; i <= t; i++)
	{
		cout << parent[i] << "\n";
	}

}