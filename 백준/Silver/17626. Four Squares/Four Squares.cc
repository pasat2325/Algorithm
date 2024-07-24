#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);

	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		int minn = INT_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			int tmp = i - j * j;
			minn = min(minn, dp[tmp]);
		}
		dp[i] = minn + 1;
	}
	cout << dp[n];
	return 0;
}