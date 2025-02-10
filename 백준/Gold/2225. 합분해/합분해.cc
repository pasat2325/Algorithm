#include <iostream>

using namespace std;
const long long mod = 1000000000;
long long dp[201][201];
int main()
{
	int n, k;
	cin >> n >> k;

	dp[0][0] = 0;

	for (int i = 1; i <= k; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 1; i <= n; i++) dp[1][i] = 1;

	for (int i = 2; i <= k; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			for (int m = 0; m <= j; m++)
				dp[i][j] += dp[i - 1][m];
			dp[i][j] %= mod;
		}

	}
	cout << dp[k][n];
}