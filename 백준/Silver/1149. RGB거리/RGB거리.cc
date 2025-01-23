#include <iostream>
#include <climits>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = arr[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
		}
	}
	
	int minnum = INT_MAX;
	for (int i = 0; i < 3; i++)
	{
		minnum = (minnum > dp[n - 1][i]) ? dp[n - 1][i] : minnum;
	}

	cout << minnum;
}