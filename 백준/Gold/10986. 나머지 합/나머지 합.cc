#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	long long remains[1000] = {0,};
	long long sum = 0;
	remains[0]++;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		remains[sum % m]++;
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		if (remains[i] >= 2) {
			ans += (remains[i] * (remains[i] - 1)) / 2;
		}
	}
	cout << ans;
}