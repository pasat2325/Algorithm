#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<string> result;
vector<int> primes;

int convert(int depth, string num) {
	int result = 0;
	for (int i = 0; i < depth; i++) {
		result *= 10;
		result += num[i] - '0';
	}
	return result;
}

bool is_prime(int depth, string num) {
	int n = convert(depth, num);
	if (n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve(int depth, string num) {
	if (depth == n) {
		result.push_back(num);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		num.push_back(i + '0');
		if (is_prime(depth + 1, num)) {
			solve(depth + 1, num);
		}
		num.pop_back();
	}
}
int main() {
	cin >> n;
	solve(0, "");

	for (auto i : result) cout << i << "\n";
}