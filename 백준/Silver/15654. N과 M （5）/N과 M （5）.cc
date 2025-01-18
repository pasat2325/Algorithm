#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>in;
vector<int>out;
bool visited[9];
int n, m;

void dfs()
{
	if (out.size() == m)
	{
		for (int i : out)
		{
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i]) {
			out.push_back(in[i]);
			visited[i] = true;
			dfs();
			out.pop_back();
			visited[i] = false;
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		in.push_back(x);
	}
	sort(in.begin(), in.end());
	dfs();
}