#include <iostream>
#include <climits>
using namespace std;
const static long long mx = 5e9;
long long dp[500][500]; // dp[i][j] == i번 행렬부터 j번 행렬까지 최소 연산 횟수
int main() {
	int n;
	int rc[501];
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		rc[i] = r;
		if (i == n - 1) rc[i + 1] = c;
	}
	// dp [i][j] 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = mx;
		}
	}

	// dp[i][i] = 0 초기화
	for (int i = 0; i < n; i++) dp[i][i] = 0;

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][k] + dp[k + 1][j] + rc[i] * rc[k + 1] * rc[j + 1], dp[i][j]);
			}
		}
	}
	cout << dp[0][n - 1];
}