#include <iostream>
using namespace std;
int main() {
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