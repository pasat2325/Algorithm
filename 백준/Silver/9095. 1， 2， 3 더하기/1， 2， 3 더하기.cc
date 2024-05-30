#include <iostream>
using namespace std;

int main() {
	int dp[11] = {1,2,4};
	int t, n;
	cin >> t;
	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n - 1] << endl;
	}

}