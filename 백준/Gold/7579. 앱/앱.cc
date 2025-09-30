#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, M; cin >> N >> M;
	vector<int>v(N + 1);
	vector<pair<int, int>> V(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	int max_cost = 0;
	for (int i = 1; i <= N; i++) {
		int f = v[i];
		int s; cin >> s;
		V[i] = { f,s };
		max_cost += s;
	}

	vector<int> dp(max_cost + 1, 0);
	for (int i = 1; i <= N; i++) {
		int mi = V[i].first;
		int ci = V[i].second;
		for (int j = max_cost; j >= 0; j--) {
			if (j - ci >= 0) {
				dp[j] = max(dp[j], dp[j - ci] + mi);
			}
		}
	}

	for (int i = 0; i <= max_cost; i++) {
		if (dp[i] >= M) {
			cout << i << "\n";
			break;
		}
	}

}