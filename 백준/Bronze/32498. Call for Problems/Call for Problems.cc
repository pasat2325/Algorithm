#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
		int x;
		cin >> x;
		if (x % 2 != 0) cnt++;
	}
	cout << cnt;
}