#include <iostream>
using namespace std;
int fact(int n) {
	if (n == 1) return 1;
	else return n * fact(n - 1);
}

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	cout << fact(n);
}