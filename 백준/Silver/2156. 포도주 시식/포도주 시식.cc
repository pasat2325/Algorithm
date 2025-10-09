#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<int> dp(n + 1);
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n];
}