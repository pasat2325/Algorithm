#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str; cin >> str;

	int ans = 0;
	for (int i = 1; i < n; i++) {
		char cur = str[i];
		char prev = str[i - 1];

		if (cur == '[' && prev == ']') continue;

		if (cur == '[' || cur == ']') ans += 1;
		else {
			if (cur == prev) ans += 2;
			else ans += 1;
		}
	}
	cout << ans;
}