#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, gmx, lmx, x;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> x;
		gmx = x;
		lmx = x;
		while (--n) {
			cin >> x;
			lmx = max(x, lmx + x);
			gmx = max(lmx, gmx);
		}
		cout << gmx << "\n";
	}
}