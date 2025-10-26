#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_N = 1'000'001;
vector<int> primes;
int find_upper(int x) {
	int L = 0, R = primes.size() - 1;
	int res = -1;
	while (L <= R) {
		int mid = (L + R) / 2;

		if (primes[mid] == x) {
			return mid;
		}

		if (primes[mid] < x) {
			L = mid + 1;
			res = mid;
		}
		else if (primes[mid] > x) {
			R = mid - 1;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<bool>is_prime(MAX_N, true);
	is_prime[0] = false; is_prime[1] = false;
	for (int i = 2; i * i < MAX_N; i++) {
		if (is_prime[i] == false) continue;
		for (int j = i * i; j < MAX_N; j += i) {
			is_prime[j] = false;
		}
	}
	for (int i = 2; i < MAX_N; i++) {
		if (is_prime[i])
			primes.push_back(i);
	}
	
	while (true) {
		int tar; cin >> tar;
		if (tar == 0) break;

		int L = 0, R = find_upper(tar);

		while (L <= R) {
			int SUM = primes[L] + primes[R];
			if (SUM == tar) {
				printf("%d = %d + %d\n", SUM, primes[L], primes[R]);
				break;
			}

			if (SUM > tar) {
				R -= 1;
			}
			else if (SUM < tar) {
				L += 1;
			}
		}
	}
}