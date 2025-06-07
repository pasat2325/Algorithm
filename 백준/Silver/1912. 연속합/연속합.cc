#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, gmx, lmx;
	cin >> n >> x;
	gmx = x;
	lmx = x;
	for (int i = 1; i < n; i++) {
		cin >> x;
		lmx = max(x, lmx + x);
		gmx = max(lmx, gmx);
	}
	cout << gmx;
}