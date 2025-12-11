#include <iostream>
using namespace std;
const int MOD = 1'000'000'007;
long long dp[5001];
int main() {
	int t; cin >> t;
	dp[0] = 1; dp[1] = 0;
	
	for (int i = 2; i <= 5000; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] += (dp[j - 2] * dp[i - j]) % MOD;
			dp[i] %= MOD;
		}
	}
	while (t--) {
		int l; cin >> l;
		cout << dp[l] << "\n";
	}
}