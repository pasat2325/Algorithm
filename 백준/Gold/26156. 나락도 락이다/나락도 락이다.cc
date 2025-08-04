#include <iostream>
using namespace std;
const int MOD = 1'000'000'007;
int main() {
	int dp[4] = { 0 };
	int n;
	cin >> n;
	string str;
	cin >> str;
	for (int i = n - 1; i >= 0; i--) {
		dp[3] *= 2;
		dp[3] %= MOD;
		if (str[i] == 'K') {
			dp[0]++;
			dp[0] %= MOD;
		}
		else if (str[i] == 'C') {
			dp[1] += dp[0];
			dp[1] %= MOD;
		}
		else if (str[i] == 'O') {
			dp[2] += dp[1];
			dp[2] %= MOD;
		}
		else if (str[i] == 'R') {
			dp[3] += dp[2];
			dp[3] %= MOD;
		}
	}
	cout << dp[3] % MOD;
}