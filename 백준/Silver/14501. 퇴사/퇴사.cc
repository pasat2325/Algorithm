#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> t, p;
	for (int i = 0; i < n; i++) {
		int tt, pp; cin >> tt >> pp;
		t.push_back(tt);
		p.push_back(pp);

	}
	int dp[20] = { 0, };

	for (int i = n - 1; i >= 0; i--) {
		if (i + t[i] <= n)
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		else dp[i] = dp[i + 1];
	}
	cout << dp[0];
}