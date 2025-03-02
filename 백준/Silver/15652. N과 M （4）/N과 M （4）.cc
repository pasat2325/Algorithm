#include <iostream>

using namespace std;

int n, m;
int arr[9];


void dfs(int start, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i <= n; i++)
	{
			arr[cnt] = i;
			dfs(i, cnt + 1);
			start++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	dfs(1,0);
}