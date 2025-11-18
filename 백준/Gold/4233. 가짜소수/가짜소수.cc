#include <iostream>
#include <math.h>
using namespace std;
using ll = long long;
const long long MAX_P = 1e9 + 1;

ll modpow(ll a, ll b, ll mod) {
	if (b == 0) return 1;
	if (b == 1) return a % mod;

	ll h = modpow(a, b / 2, mod);
	ll r = (h * h) % mod;
	if (b % 2 == 1) {
		r = (r * a) % mod;
	}
	return r;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		int p, a; cin >> p >> a;
		if (p == 0 && a == 0) break;

		bool is_prime = true;
		for (int i = 2; i <= sqrt(p); i++) {
			if (p % i == 0) {
				is_prime = false;
				break;
			}
		}

		if (is_prime) {
			cout << "no" << "\n";
			continue;
		}

		if (modpow(a, p, p) == a % p) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}