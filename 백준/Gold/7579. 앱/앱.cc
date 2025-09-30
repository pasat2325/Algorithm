#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<int> bytes(N + 1);
	vector<int> costs(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> bytes[i];
	}
	int max_cost = 0;
	for (int i = 1; i <= N; i++) {
		cin >> costs[i];
		max_cost += costs[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(max_cost + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= max_cost; j++) {
			if (j - costs[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - costs[i]] + bytes[i]);
			}
			dp[i][j] = max(dp[i - 1][j], dp[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= max_cost; i++) {
		if (dp[N][i] >= M) {
			ans = i;
			break;
		}
	}
	cout << ans;
}