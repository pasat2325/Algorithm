#include <iostream>
#include <vector>
using namespace std;

int cal_gcd(int x, int y) {
	return x % y ? cal_gcd(y, x % y) : y;
}

int main() {
	int n; cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}
	int gcd = tree[1] - tree[0];
	for (int i = 1; i < n - 1; i++) {
		int dist = tree[i + 1] - tree[i];
		gcd = cal_gcd(dist, gcd);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		int dist = tree[i + 1] - tree[i];
		ans += dist / gcd - 1;
	}
	cout << ans;
}