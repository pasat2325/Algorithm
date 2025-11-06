#include <iostream>
using namespace std;
int main() {
	long long n; cin >> n;

	if ((n - 1) % 5 == 0 || (n - 3) % 5 == 0 || (n - 4) % 5 == 0) {
		cout << "SK";
	}
	else cout << "CY";
}