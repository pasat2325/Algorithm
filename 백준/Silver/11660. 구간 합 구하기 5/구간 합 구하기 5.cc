#include <iostream>

using namespace std;

int arr[1024][1024];
int dp[1024][1024];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			
			arr[i][j] = x;
			
			if (j == 0) dp[i][j] = x;
			else dp[i][j] = arr[i][j] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		int result = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1 - 1; j <= x2 - 1; j++)
		{
			if (y1 - 1 == 0) result += dp[j][y2 - 1];
 			else result += dp[j][y2 - 1] - dp[j][y1 - 2];
		}
		cout << result << "\n";
	}
	
}