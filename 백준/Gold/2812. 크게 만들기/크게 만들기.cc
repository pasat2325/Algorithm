#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	stack<int> st;
	for (int i = 0; i < str.length(); i++) {
		if (st.empty()) {
			st.push(str[i] - '0');
			continue;
		}

		while (!st.empty() && st.top() < (str[i] - '0') && k > 0) {
			st.pop();
			k -= 1;
		}
		st.push(str[i] - '0');
	}
	while (k > 0) {
		k -= 1;
		st.pop();
	}
	string res = "";
	while (!st.empty()) {
		res.push_back(st.top() + '0');
		st.pop();
	}
	reverse(res.begin(), res.end());
	cout << res;
}