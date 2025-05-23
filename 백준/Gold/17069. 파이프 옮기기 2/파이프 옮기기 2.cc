#include <iostream>
using namespace std;
int map[32][32];
long long dp[32][32][3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> map[i][j];


	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (map[i][j] == 1) continue;

			if (j + 1 < n && map[i][j + 1] == 0) dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][2];
			if (i + 1 < n && map[i + 1][j] == 0) dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][2];
			if (i + 1 < n && j + 1 < n && map[i + 1][j + 1] == 0 && map[i][j+1] == 0 && map[i + 1][j] == 0)
				dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
		}
	}
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}