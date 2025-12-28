#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dp[100'001];

int main() {
	int N, K; cin >> N >> K;
	vector<int> cof(N);
	for (int i = 0; i < N; i++) {
		cin >> cof[i];
	}

	for (int i = 0; i <= K; i++) {
		dp[i] = 101;
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		int cur_caf = cof[i];

		for (int j = K; j > 0; j--) {
			if (j >= cur_caf) {
				dp[j] = min(dp[j - cur_caf] + 1, dp[j]);
			}
		}
	}
	if (dp[K] == 101) cout << -1;
	else cout << dp[K];
}