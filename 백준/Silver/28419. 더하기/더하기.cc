#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long long even_sum = 0;
	long long odd_sum = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i % 2 == 0) {
			even_sum += x;
		}
		else {
			odd_sum += x;
		}
	}
	if (odd_sum == even_sum) {
		cout << 0 << "\n";
		return 0;
	}

	if (n == 3 && odd_sum > even_sum) {
		cout << -1 << "\n";
		return 0;
	}
	
	cout << abs(even_sum - odd_sum) << "\n";
	return 0;
}

