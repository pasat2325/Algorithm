#include <iostream>
#define MAX_W 100001
using namespace std;
int dp[MAX_W];
int main() {
	int n, k;
	cin >> n >> k;
	int weights[100];
	int values[100];
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		weights[i] = w;
		values[i] = v;
	}
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) {
			if (weights[i] > j) break;
			dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
		}
	}
	cout << dp[k];
	return 0;
}