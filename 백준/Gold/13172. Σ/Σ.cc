	#include <iostream>
	#define MOD 1000000007
	using namespace std;
	int n, s;


	long long mod_reverse(long long x, long long y) {
		if (y == 1) return x;

		if (y % 2 == 1) return (x * mod_reverse(x, y - 1)) % MOD;
	
		long long half = mod_reverse(x, y / 2);
		return (half * half) % MOD;
	}
	int main() {
		int t;
		cin >> t;
		long long ans = 0;
		for (int i = 0; i < t; i++) {
			cin >> n >> s;
			long long value = (s * mod_reverse(n, MOD - 2)) % MOD;
			ans += value;
			ans %= MOD;
		}
		cout << ans;
	}