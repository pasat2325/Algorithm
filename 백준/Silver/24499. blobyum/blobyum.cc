#include <iostream>
using namespace std;
const int MAX_N = 1e5;
int arr[MAX_N * 2];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		arr[i] = x;
		arr[i + n] = x;
	}

	for (int i = 1; i < 2 * n; i++) {
		arr[i] = arr[i] + arr[i - 1];
	}

	int res = arr[k - 1];
	for (int i = 1; i < n; i++) {
		int sum = arr[i + k - 1] - arr[i - 1];
		res = max(sum, res);
	}
	cout << res;
}