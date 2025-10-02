#include <iostream>
#include <stack>
using namespace std;
int main() {
	string str;
	cin >> str;
	stack<int> st;
	for (int i = 0; i < str.length(); i++) {
		st.push(str[i] - '0');
	}

	bool a = false;
	bool new_pattern = true;
	bool first_pattern_started = false;
	int zc = 0;

	if (st.size() == 1 && st.top() == 1) {
		cout << "NOISE";
		return 0;
	}
	while (!st.empty()) {
		if (new_pattern) {
			if (st.top() == 0) {
				break;
			}
			st.pop();
			new_pattern = false;
			if (st.empty()) a = true;
		}

		else {
			if (first_pattern_started) {
				if (zc >= 2 && st.top() == 1) {
					st.pop();
					first_pattern_started = false;
					new_pattern = true;
					zc = 0;
				}
				else if (zc == 1 && st.top() == 1) {
					break;
				}
				else if (st.top() == 0) {
					zc += 1;
					st.pop();
					if (st.empty()) a = true;
				}
				else if (st.top() == 1) {
					st.pop();
					if (st.empty())
						a = true;
				}
			}
			else if (st.top() == 0) {
				st.pop();
				if (st.empty() || st.top() != 0) {
					new_pattern= true;
				}
				else {
					first_pattern_started = true;
					zc += 1;
					if (st.empty()) a = true;
				}
			}
			else {
				st.pop();
				first_pattern_started = true;
				if (st.empty()) a = true;
			}
		}
	}
	if (!st.empty() || a) cout << "NOISE";
	else cout << "SUBMARINE";
}