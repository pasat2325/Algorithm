#include <iostream>
using namespace std;
int main() {
	int k; cin >> k;

	int t = 1;
	while (k > t) {
		t <<= 1;
	}
	int s = t;
	int cnt = 0;
	while (k) {
		if (k < t) {
			t /= 2;
			cnt++;
		}
		else {
			k -= t;
		}
	}
	cout << s << " " << cnt;
	
}