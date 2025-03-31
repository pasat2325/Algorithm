#include <iostream>
using namespace std;
int main() {
	int x, b = 2001, d = 2001;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		if (b > x) b = x;
	}
	for (int i = 0; i < 2; i++) {
		cin >> x;
		if (d > x) d = x;
	}
	cout << b + d - 50;
}