#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	int res = 0;
	int num;
	bool isminus = false;
	string nums = {};

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' or s[i] == '-' or i == s.size()) {
			num = stoi(nums);
			nums = {};
			if (isminus) {
				res -= num;
			}
			else {
				res += num;
			}
			if (s[i] == '-') isminus = true;

		}
		else nums += s[i];
	}
	cout << res;
}