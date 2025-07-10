#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 300001
using namespace std;
vector<int> v(MAX_N, 1001);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	v[0] = 0;
	sort(v.begin() + 1, v.end());
	for (int i = 1; i <= n; i++) {
		v[i] = v[i - 1] + v[i];
	}
	while (q--) {
		int l, r; cin >> l >> r;

		cout << v[r] - v[l - 1] << "\n";
	}
}