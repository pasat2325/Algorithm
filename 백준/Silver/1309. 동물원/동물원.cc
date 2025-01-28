#include <iostream>
#define mod %9901
using namespace std;

long long dp[100000][3];
int n;

int main()
{
	cin >> n;
	
	for (int i = 0; i < 3; i++) dp[0][i] = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1])mod;
	}

	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2])mod;
}