#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int t; cin >> t;
	vector<bool>v(10002, false);
	v[1] = true;
	for (int i = 2; i < 10002; i++) {
		for (int j = 2; i * j < 10002; j++) {
			int x = i * j;

			v[x] = true;
		}
	}
	
	while (t--) {
		int n; cin >> n;
		if (v[n + 1] == false) {
			cout << 1 << "\n";
			cout << 1 << " " << n + 1 << "\n";
		}
		else cout << 0 << "\n";
	}
	return 0;
}