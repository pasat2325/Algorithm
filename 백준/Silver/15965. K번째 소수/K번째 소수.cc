#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_prime(500'001, true);
vector<int> primes;

int main() {
	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i * i < 500'001; i++) {
		if (!is_prime[i]) continue;

		for (int j = i * 2; j < 500'001; j += i) {
			is_prime[j] = false; 
		}
	}
	
	for (int i = 2; i < 500'001; i++) {
		if (is_prime[i]) primes.push_back(i);
	}

	int k; cin >> k;
	k -= 1;
	cout << primes[k];
}