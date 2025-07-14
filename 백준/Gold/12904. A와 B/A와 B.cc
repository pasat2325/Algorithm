#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s, t;
	cin >> s >> t;
	int sl = s.length();
	int tl = t.length();

	while (tl > sl) {
		char rear = t[--tl];
		if (rear == 'A') t.pop_back();
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	if (t == s) cout << 1;
	else cout << 0;
}