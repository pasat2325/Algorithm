#include <iostream>
using namespace std;
int dp[2500][2500];

int main() {
	string str;
	cin >> str;

	int n = str.length();
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	
	for (int i = 1; i < n; i++) {

		dp[0][i] = dp[0][i - 1] + 1;

		for (int j = 0; j <= i; j++) {
			if (str[i] == str[j]) {
				// isPalindrome
				if (dp[j + 1][i - 1] == 1 || i - 1 == j) {
					dp[j][i] = 1;
					if (j == 0) dp[0][i] = 1;
					else dp[0][i] = min(dp[0][i], dp[0][j - 1] + 1);

				}
			}

		}

	}
	cout << dp[0][n - 1];
}