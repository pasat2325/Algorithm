
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 10'001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	vector<bool> is_prime(MAX + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= MAX; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
	while (t--) {
		int n; cin >> n;
		if (is_prime[n + 1]) {
			cout << 1 << "\n" << 1 << " " << n + 1 << "\n";
		}
		else cout << 0 << "\n";
	}
	return 0;
}