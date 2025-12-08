#include <iostream>
using namespace std;
int main() {
	int n; cin >> n;
	int dp[1001] = {0,};

	for (int i = 1; i <= n; i++) {
		cin >> dp[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i - j] + dp[j], dp[i]);
		}
	}
	cout << dp[n];
}