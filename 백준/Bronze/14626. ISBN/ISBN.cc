#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int a[13];
	int ei = 0;
	for (int i = 0; i < 13; i++) {
		if (str[i] == '*') {
			ei = i;
			a[i] = 0;
			continue;
		}
		if (i % 2 == 0) a[i] = str[i] - '0';
		else a[i] = (str[i] - '0') * 3;
	}
	int ans = 0;
	for (int i = 0; i<= 9 ; i++) {
		if (ei % 2 == 0) a[ei] = i;
		else a[ei] = i * 3;
		int sum = 0;
		for (int j = 0; j < 12; j++) {
			sum += a[j];
		}
		if (a[12] == 10 - ((sum % 10) == 0 ? 10 : sum % 10)) ans = i;
	}
	cout << ans;
}