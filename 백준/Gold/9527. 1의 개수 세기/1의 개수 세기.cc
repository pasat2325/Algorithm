#include <iostream>
using namespace std;

int cal_top_bit_index(long long n) {
	long long top = 1;
	int idx = 0;
	while ((top << 1) <= n) {
		top <<= 1;
		idx++;
	}
	return idx;
}

long long solve(long long n) {
	if (n == 0) return 0;

	int top_bit_index = cal_top_bit_index(n);
	long long d[64];
	d[0] = 1;
	for (int i = 1; i <= top_bit_index; i++) {
		d[i] = d[i - 1] * 2ull + (1ull << i);
	}

	long long res = 0;
	for (int i = top_bit_index; i >= 0; i--) {
		if (!(1ull << i & n)) continue;
		if (i == 0) {
			res += 1;
			break;
		}
		res += d[i - 1] + (n - (1ull << i) + 1ull);
		n -= (1ull << i);
	}
	return res;
}

int main() {
	long long a, b;
	cin >> a >> b;

	cout << solve(b) - solve(a - 1);

}