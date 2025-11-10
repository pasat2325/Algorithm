#include <iostream>
#include <vector>
using namespace std;
int dp[10'001] = { 0, };
int main() {
	int n, m; cin >> n >> m;
	
	vector<int> t, s;
	
	t.resize(n);
	s.resize(n);
	
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= 0; j--) {
			if (j - t[i] < 0) continue;
			dp[j] = max(dp[j], dp[j - t[i]] + s[i]);
		}
	}
	cout << dp[m];
}