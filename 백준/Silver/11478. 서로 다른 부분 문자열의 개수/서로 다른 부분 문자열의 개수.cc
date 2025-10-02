#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	long long ans = 0;
	unordered_map<string, bool>M;
	int nn = str.length();
	for (int i = 0; i < nn; i++) {
		for (int j = 1; j <= nn - i; j++) {
			string tmp = str.substr(i, j);
			
			if (M.find(tmp) == M.end()) {
				M[tmp] = true;
				ans++;
			}
		}
	}
	cout << ans;
}