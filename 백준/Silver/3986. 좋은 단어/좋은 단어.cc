#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int ans = 0;
	while (n--) {
		string str;
		cin >> str;
		if (str.length() % 2 != 0) {
			continue;
		}
		stack<char>st;
		for (int i = 0; i < str.length(); i++) {
			if (st.empty()) {
				st.push(str[i]);
				continue;
			}
			if (st.top() == str[i]) {
				st.pop();
			}
			else {
				st.push(str[i]);
			}
		}
		if (st.empty()) ans++;
	}
	cout << ans;
}