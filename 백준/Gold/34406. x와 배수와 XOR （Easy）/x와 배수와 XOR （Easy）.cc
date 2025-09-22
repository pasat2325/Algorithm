#include <iostream>
using namespace std;
int bitlen(unsigned x) {
	int len = 0;
	while (x > 0) {
		len++;
		x >>= 1;
	}
	return len;
}

int main() {
	int t; cin >> t;
	while (t--) {
		unsigned n; cin >> n;
		if (n == 0) {
			cout << 1 << "\n2\n";
			continue;
		}
		int n_bit_len = bitlen(n);
		unsigned k1 = 1u << n_bit_len;
		unsigned k2 = (1u << n_bit_len) + 1u;
		cout << 2 << "\n" << k1 << " " << k2 << "\n";
	}
}