#include <iostream>
#define MAX_N 16
#define MAX_V 65536
#define INF 1e8
using namespace std;

int n;
int w[MAX_N][MAX_N];
int dp[MAX_N][MAX_V];

bool visited(int bits, int city) {
	if (bits & (1 << city)) return true;
	return false;
}
int visit(int bits, int city) {
	return (bits | (1 << city));
}

int tsp(int here, int bits) {
	if (bits == (1 << n) - 1) return (w[here][0] != 0) ? w[here][0] : INF;

	if (dp[here][bits] != -1) return dp[here][bits];
	dp[here][bits] = INF;
	for (int next = 0; next < n; next++) {
		if (!visited(bits, next) && w[here][next] != 0) {
			int cost = tsp(next, visit(bits, next)) + w[here][next];
			if (cost < dp[here][bits]) dp[here][bits] = cost;	
		}
	}
	return dp[here][bits];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		fill_n(dp[i], size(dp[i]), -1);
	}
	cout << tsp(0, 1);
}