#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	long long ans = 0;
	unordered_set<string> st;
	int nn = str.length();
	for (int i = 0; i < nn; i++) {
		for (int j = 1; j <= nn - i; j++) {
			string tmp = str.substr(i, j);
			
			if (st.insert(tmp).second) {
				ans += 1;
			}
		}
	}
	cout << ans;
}