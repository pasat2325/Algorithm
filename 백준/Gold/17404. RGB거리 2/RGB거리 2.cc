#include <iostream>
#include <algorithm>
#define MAX_COST 1000
using namespace std;

int dp[1001][3];
int costs[1001][3];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		costs[i][0] = r;
		costs[i][1] = g;
		costs[i][2] = b;
	}

	//1. 1번집을 빨간색으로 칠하는 경우
	int cr;
	dp[1][0] = costs[1][0];
	dp[1][1] = MAX_COST + 1;
	dp[1][2] = MAX_COST + 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
	}
	cr = min(dp[n][1], dp[n][2]);

	//2. 1번집을 초록색으로 칠하는 경우
	int cg;
	dp[1][1] = costs[1][1];
	dp[1][0] = MAX_COST + 1;
	dp[1][2] = MAX_COST + 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
	}
	cg = min(dp[n][0], dp[n][2]);

	//3. 1번집을 파랑색으로 칠하는 경우
	int cb;
	dp[1][2] = costs[1][2];
	dp[1][1] = MAX_COST + 1;
	dp[1][0] = MAX_COST + 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
	}
	cb = min(dp[n][0], dp[n][1]);

	int ans = min({ cr, cg, cb });
	//cout << cr << " " << cg << " " << cb;
	cout << ans;

	
}