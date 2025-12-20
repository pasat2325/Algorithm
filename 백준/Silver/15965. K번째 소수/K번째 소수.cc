#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10'000'000;

vector<bool> is_prime(MAX, true);
vector<int> primes;

int main() {
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i * i < MAX; i++) {
		if (!is_prime[i]) continue;

		for (int j = i * 2; j < MAX; j += i) {
			is_prime[j] = false; 
		}
	}
	
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) primes.push_back(i);
	}

	int k; cin >> k;
	k -= 1;
	cout << primes[k];
}