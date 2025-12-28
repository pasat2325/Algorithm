#include <iostream>
#include <algorithm>
using namespace std;

long long dp[20'001];
long long oranges[20'001];

int main() {
	long long N, M, K; cin >> N >> M >> K;
	
	for (long long i = 1; i <= N; i++) {
		cin >> oranges[i];
		dp[i] = dp[i - 1] + K;
	}
	for (long long i = 2; i <= N; i++) {
		long long rg = max(i - M + 1, (long long)1);

		long long local_max = oranges[i];
		long long local_min = oranges[i];

		for (long long j = i; j >= rg; j--) {
			local_max = max(local_max, oranges[j]);
			local_min = min(local_min, oranges[j]);

			long long cost = K + (i - j + 1) * (local_max - local_min);

			dp[i] = min(dp[j - 1] + cost, dp[i]);
		}
	}
	cout << dp[N];

}