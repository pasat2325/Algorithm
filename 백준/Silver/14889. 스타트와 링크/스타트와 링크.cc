#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool check_ten(int n, int m) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (m & (1 << i)) cnt++;
	}
	if (cnt == n / 2) return true;
	return false;
}

int main() {
	int n;
	cin >> n;
	int map[20][20] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
\
	int ans = INT_MAX;
	for (int i = 0; i < (1 << n); i++) {
		if (!check_ten(n, i)) continue;
		vector<int> st;
		vector<int> lk;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				st.push_back(j);
			}
			else lk.push_back(j);
		}

		int st_stat = 0;
		int lk_stat = 0;
		for (int j = 0; j < n / 2; j++) {
			for (int k = j + 1; k < n / 2; k++) {
				st_stat += map[st[j]][st[k]] + map[st[k]][st[j]];
				lk_stat += map[lk[j]][lk[k]] + map[lk[k]][lk[j]];
			}
		}
		ans = min(ans, abs(st_stat - lk_stat));
	}
	cout << ans;
}