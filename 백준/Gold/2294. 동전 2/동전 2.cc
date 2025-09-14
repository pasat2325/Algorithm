#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n, k; cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	vector<int> dp(k + 1, 10'001);
	dp[k] = 0;
	for (int i = k; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			int curr = coins[j];
			if (i - curr < 0) continue;
			dp[i - curr] = min(dp[i - curr], dp[i] + 1);
		}
	}
	if (dp[0] == 10'001) cout << -1;
	else cout << dp[0];
}