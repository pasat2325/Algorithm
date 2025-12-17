#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;

	// 전체를 0으로 만드는 경우 1이 연속된 구간의 개수를 구하기
	bool x = false;
	int ocnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' && x) {
			ocnt += 1;
			x = false;
		}
		else if (str[i] == '1' && !x) {
			x = true;
		}
	}
	if (x) ocnt += 1;

	// 전체를 1로 만드는 경우 0이 연속된 구간의 개수를 구하기
	x = false;
	int zcnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '1' && x) {
			zcnt += 1;
			x = false;
		}
		else if (str[i] == '0' && !x) {
			x = true;
		}
	}
	if (x) zcnt += 1;

	cout << min(ocnt, zcnt);
}