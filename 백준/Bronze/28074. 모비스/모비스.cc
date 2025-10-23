#include <iostream>

using namespace std;
int main() {
	string str; cin >> str;
	bool cc[26] = { false };
	for (auto c : str) {
		cc[c - 'A'] = true;
	}
	string ans = "MOBIS";
	bool r = true;
	for (auto c : ans) {
		if (cc[c - 'A'] == false) {
			r = false;
			break;
		}
	}
	if (r) cout << "YES";
	else cout << "NO";
}