#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int L = 0;
	int R = n - 1;
	int ans = 1e9;
	while (L < R) {
		int diff = v[L] + v[R];
		if (diff == 0) {
			cout << 0 << "\n";
			return 0;
		}
		else if (diff > 0) {
			ans = abs(ans) > abs(diff) ? diff : ans;
			R -= 1;
		}
		else {
			ans = abs(ans) > abs(diff) ? diff : ans;
			L += 1;
		}
	}
	cout << ans << "\n";
	return 0;
}