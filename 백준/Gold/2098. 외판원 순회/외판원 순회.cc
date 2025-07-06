#include <iostream>
#define MAX_N 16
#define MAX_V 65536
#define INF 1e9

using namespace std;

int n;
int w[MAX_N][MAX_N];
int dp[MAX_N][MAX_V];

bool has_visited(int bits, int city) {
	if (bits & (1 << city)) return true;
	else return false;
}
int visit(int bits, int city) {
	return (bits | (1 << city));
}

int tsp(int here, int state) {
	if (state == (1 << n) - 1) {
		if (w[here][0]) {
			return w[here][0];
		}
		return INF;
	}
	if (dp[here][state] != 0) return dp[here][state];
	dp[here][state] = INF;
	for (int nx = 0; nx < n; nx++) {
		if (has_visited(state, nx)) continue;

		if (w[here][nx]) {
			int ncost = w[here][nx] + tsp(nx, visit(state, nx));
			dp[here][state] = min(dp[here][state], ncost);
		}
	}
	return dp[here][state];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> w[i][j];

	cout << tsp(0, 1);
}