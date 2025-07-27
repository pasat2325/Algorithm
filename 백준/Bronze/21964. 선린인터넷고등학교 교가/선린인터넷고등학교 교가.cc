#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		if (n - i <= 5) cout << x;
	}
}