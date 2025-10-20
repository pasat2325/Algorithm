#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		unordered_map<int, bool> saw;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			saw.insert({ x, true });
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (saw.find(x) != saw.end()) {
				cout << 1 << "\n";
				continue;
			}
			cout << 0 << "\n";
		}
	}
}