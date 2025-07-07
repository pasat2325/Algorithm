#include <iostream>
#define MOD 100000
using namespace std;
int dp[101][101][2][2]; //x,y,dir,turn_avail

int main() {
	int w, h;
	cin >> w >> h;
	for (int i = 2; i <= w; i++) dp[i][1][0][0] = 1;
	for (int i = 2; i <= h; i++) dp[1][i][1][0] = 1;
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MOD;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			ans += dp[w][h][i][j];
		}
	}
	cout << ans % MOD;
}