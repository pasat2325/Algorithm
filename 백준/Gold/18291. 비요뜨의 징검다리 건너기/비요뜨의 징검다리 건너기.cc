#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modpow(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a % MOD;

	ll h = modpow(a, b / 2);
	ll result = (h * h) % MOD;

	if (b % 2 == 1) {
		result = (result * a) % MOD;
	}
	return result;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int nn = n - 2;

		if (n == 1) {
			cout << 1 << "\n";
		}
		else {
			cout << modpow(2, nn) << "\n";
		}
		
	}
}