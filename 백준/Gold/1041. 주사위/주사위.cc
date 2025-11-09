#include <iostream>
#include <algorithm>
using namespace std;

long long dice[6];
long long dp[1'000'001];
int main() {
	long long n; cin >> n;
	long long maxd = 0; long long mind = 51;
	int all = 0;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		maxd = max(maxd, dice[i]);
		mind = min(mind, dice[i]);
		all += dice[i];
	}

	// 2면 (인접하는 형태) 최소 구하기
	// (0,5), (1,4), (2,3) 제외
	long long two = 101;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i == 0 && j == 5) continue;
			if (i == 1 && j == 4) continue;
			if (i == 2 && j == 3) continue;
			two = min(two, dice[i] + dice[j]);
		}
	}

	// 3면 (인접하는 형태) 최소 구하기
	long long three = min({ dice[0] + dice[1] + dice[2],
		dice[0] + dice[1] + dice[3], dice[0] + dice[3] + dice[4],
		dice[0] + dice[2] + dice[4], dice[3] + dice[5] + dice[4],
		dice[2] + dice[1] + dice[5], dice[2] + dice[5] + dice[4],
		dice[1] + dice[3] + dice[5]});

	if (n == 1) {
		cout << all - maxd;
	}
	else if (n == 2) {
		cout << three * 4 + two * 4;
	}
	else {
		long long top_ring = three * 4 + (two * (n - 2) * 4);
		long long middle_ring = two * (n - 2) * 4;
		long long bottom_ring = two * 4 + (mind * (n - 2) * 4);

		cout << top_ring + middle_ring + bottom_ring + (n - 2) * (n - 2) * 5 * mind;
	}

}