#include <iostream>
#include <cstring>
using namespace std;
bool check(int org_n[], int com_n[], bool f) {
	int diff_sum = 0;
	for (int i = 0; i < 26; i++) {
		diff_sum += abs(org_n[i] - com_n[i]);
	}
	if (f) {
		if (diff_sum == 1) return true;
		else return false;
	}
	else {
		if (diff_sum == 2 || diff_sum == 0) return true;
		else return false;
	}
}
int main() {
	int n, ans = 0;
	string org;
	string com;
	int org_n[26] = { 0 };
	int com_n[26] = { 0 };
	cin >> n >> org;
	int org_length = org.length();
	for (int i = 0; i < org_length; i++) {
		org_n[org[i] - 'A']++;
	}
	while (--n) {
		bool vist = false;
		cin >> com;
		int com_length = com.length();
		memset(com_n, 0, sizeof(com_n));
		for (int i = 0; i < com_length; i++) {
			com_n[com[i] - 'A']++;
		}
		if (org_length == com_length) {
			vist = check(org_n, com_n, 0);
		}
		else if (abs(org_length - com_length) == 1) {
			vist = check(org_n, com_n, 1);
		}
		if (vist) ans++;
	}
	cout << ans;
}