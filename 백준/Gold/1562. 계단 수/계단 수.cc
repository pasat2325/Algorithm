#include <iostream>
#define MOD 1000000000
using namespace std;
int n;
int dp[10][101][1024];

int update_status(int digit, int status) {
	return (status | (1 << digit));
}

int solve(int digit, int length, int status) {
	if (length == n) {
		if (status == (1 << 10) - 1) return 1;
		else return 0;
	}
	if (dp[digit][length][status] != 0) return dp[digit][length][status];

	int tmp = 0;
	if (digit < 9) {
		int nx_digit = digit + 1;
		tmp += solve(nx_digit, length + 1, update_status(nx_digit, status));
		tmp %= MOD;
	}
	if (digit > 0) {
		int nx_digit = digit - 1;
		tmp += solve(nx_digit, length + 1, update_status(nx_digit, status));
		tmp %= MOD;
	}
	return dp[digit][length][status] = tmp;
}

int main() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += solve(i, 1, update_status(i, 0));
		ans %= MOD;
	}
	cout << ans;
}