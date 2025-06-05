#include <iostream>
#include <vector>
using namespace std;
int dp[100001][5][5];

int get_weight(int from, int to) {
	if (from == 0) return 2;
	if (from == to) return 1;
	if ((from == 1 && to == 3) || (from == 3 && to == 1)) return 4;
	if ((from == 2 && to == 4) || (from == 4 && to == 2)) return 4;
	return 3;
}

int main() {
	vector<int> v;
	while (true) {
		int x;
		cin >> x;
		if (x == 0) break;
		v.push_back(x);
	}
	// 처음에 왼발을 먼저 움직이는 경우
	dp[0][v.front()][0] = 2;
	// 처음에 오른발을 먼저 움직이는 경우
	dp[0][0][v.front()] = 2;
	
	for (int i = 1; i < v.size(); i++) {
		int t = v[i];

		for (int l = 0; l <= 4; l++) {
			for (int r = 0; r <= 4; r++) {
				if (dp[i - 1][l][r] == 0) continue;

				int wl = get_weight(l, t);
				int wr = get_weight(r, t);

				// 왼발 이동
				if (t != r) {
					if (dp[i][t][r] == 0 || dp[i][t][r] > dp[i - 1][l][r] + wl) dp[i][t][r] = dp[i - 1][l][r] + wl;
				}
				// 오른발 이동
				if (t != l) {
					if (dp[i][l][t] == 0 || dp[i][l][t] > dp[i - 1][l][r] + wr) dp[i][l][t] = dp[i - 1][l][r] + wr;
				}
			}
		}
	}
	int ans = 1e9;
	int n = v.size() - 1;
	for (int l = 0; l <= 4; l++) {
		for (int r = 0; r <= 4; r++) {
			if (dp[n][l][r] != 0) {
				ans = min(ans, dp[n][l][r]);
			}
		}
	}
	cout << ans;
}