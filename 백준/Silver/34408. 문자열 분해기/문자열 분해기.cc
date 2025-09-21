#include <iostream>
using namespace std;
int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;

	int strc1[30] = { 0, };
	int strc2[30] = { 0, };

	for (int i = 0; i < str1.length(); i++) {
		char ch = str1[i];
		strc1[ch - 'A'] += 1;
	}
	for (int i = 0; i < str2.length(); i++) {
		char ch = str2[i];
		strc2[ch - 'A'] += 1;
	}
	bool able = true;
	for (int i = 0; i < str2.length(); i++) {
		char ch = str2[i];
		if (strc2[ch - 'A'] > strc1[ch - 'A']) able = false;
	}
	if (able)
		cout << "OK";
	else cout << "NEED FIX";
}