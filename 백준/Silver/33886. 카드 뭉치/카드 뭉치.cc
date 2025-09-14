#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int>cards(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cards[i];
	}
	vector<int> dp(n + 1, 3001);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int l = i - j + 1;
			if (cards[j] >= l) {
				dp[i] = min(dp[j - 1] + 1, dp[i]);
			}
		}
	}
	cout << dp[n];

}