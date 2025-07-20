#include <iostream>
#include <cstring>
using namespace std;

bool check(int org_n[], int com_n[]) {
	for (int i = 0; i < 26; i++) {
		if (org_n[i] != com_n[i]) return false;
	}
	return true;
}
int main() {
	int n, ans = 0;
	string org;
	string com;
	int org_n[26] = { 0 };
	int com_n[26] = { 0 };
	int org_length;
	int com_length;
	cin >> n >> org;
	org_length = org.length();
	for (int i = 0; i < org_length; i++) {
		org_n[org[i] - 'A']++;
	}
	for (int d = 0; d < n - 1; d++) {
		cin >> com;
		com_length = com.length();
		memset(com_n, 0, sizeof(com_n));
		for (int i = 0; i < com_length; i++) {
			com_n[com[i] - 'A']++;
		}
		bool vist = false;
		if (com_length == org_length + 1) {
			for (int i = 0; i < 26; i++) {
				org_n[i]++;
				vist = check(org_n, com_n);
				org_n[i]--;
				if (vist) break;
			}
		}
		else if (com_length == org_length - 1) {
			for (int i = 0; i < 26; i++) {
				org_n[i]--;
				vist = check(org_n, com_n);
				org_n[i]++;
				if (vist) break;
			}
		}
		else if (com_length == org_length) {
			for (int i = 0; i < 26; i++) {
				org_n[i]--;
				for (int j = 0; j < 26; j++) {
					org_n[j]++;
					vist = check(org_n, com_n);
					org_n[j]--;
					if (vist) break;
				}
				org_n[i]++;
				if (vist) break;
			}
		}
		else continue;
		if (vist) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}