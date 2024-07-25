#include <iostream>
#include<climits>

using namespace std;

int tri[501][501];
int dp[501][501];

int main()
{
	int h;
	cin >> h;

	

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			int a;
			cin >> a;
			tri[i][j] = a;
		}
	}
	
	for (int i = 0; i < h; i++)
	{
		dp[h - 1][i] = tri[h - 1][i];
	}

	for (int i = h - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++) {
			dp[i - 1][j] = tri[i - 1][j] + max(dp[i][j], dp[i][j + 1]);
		}
	}
	cout << dp[0][0];
}