#include <iostream>
using namespace std;
int main() {
	string n;
	cin >> n;
	int count = 0;
	char s = n[1];
	int a = 0;
	for (int i = 0; i < n.length() / 2; i++) {
		if (n[i] == n[n.length() - 1 - i])
			count += 1;
	}
	if (count == n.length() / 2) {
		for (int i = 0; i < n.length(); i++) {
			if (s == n[i]) {
				a += 1;
			}
		}
		if (a == n.length()) {
			cout << -1;
		}
		else if (n.length() == 1)
			cout << -1;
		else cout << n.length() - 1;
	}
	else
		cout << n.length();
}