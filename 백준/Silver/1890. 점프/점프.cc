#include <iostream>
#include <vector>

using namespace std;

int n;
int map[100][100];
long long dp[100][100];

void solve()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 0 || (i == n-1 && j == n - 1)) continue;

			int val = map[i][j];
			int nextx = i + val;
			int nexty = j + val;

			if (nextx < n) dp[nextx][j] = dp[nextx][j] + dp[i][j];

			if (nexty < n) dp[i][nexty] = dp[i][nexty] + dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1];
}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			map[i][j] = x;
		}
	}
	dp[0][0] = 1;
	solve();
}