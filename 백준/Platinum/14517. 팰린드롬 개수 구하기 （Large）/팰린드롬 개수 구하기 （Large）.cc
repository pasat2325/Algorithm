#include <iostream>
using namespace std;

const int MOD = 10007;

int dp[1000][1000]; // index i ~ j 범위 내의 팰린드롬 부분 수열의 개수를 저장한다.
int main() {
	string str;
	cin >> str;

	int n = str.length();

	// dp[a][a] => 한 글자는 그 자체로 팰린드롬이다.
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	// i ~ j 범위의 크기가 2일 때, (곧바로 연속될 때) 
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1])
			dp[i][i + 1] = 3;
		else
			dp[i][i + 1] = 2;
	}

	// i ~ j 범위의 크기가 3일 때, 즉 i ~ j 범위 내에 i, j를 포함 또는 미포함하는 부분 수열이 존재할 때
	// 하위 문제가 존재하는 구간

	for (int L = 3; L <= n; L++) {
		for (int i = 0; i <= n - L; i++) {
			int j = i + (L - 1);

			if (str[i] == str[j]) {
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
				dp[i][j] %= MOD;
			}
			else {
				dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
			}
		}
	}
	cout << dp[0][n - 1];

}