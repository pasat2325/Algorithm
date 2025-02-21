#include <iostream>

using namespace std;
const static int r = 1000000007;

int main()
{
	int n;
	cin >> n;

	int dp[1516][3];

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 0;

	for (int i = 2; i <= 1515; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % r;
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][0]) % r;
		dp[i][2] = (dp[i - 1][1] + dp[i - 1][0]) % r;
	}
	cout << dp[n][0];
}