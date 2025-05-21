#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;
char op[4] = { '*', '+', '-', '/' };
int s, t;
vector<string> v;
map<long long, int> m;
int length = INT_MAX;

void solve(long long n, string ops) {
	if (n == t) {
		if (ops.length() < length) {
			length = ops.length();
			v.clear();
			v.push_back(ops);
		}
		else if (ops.length() == length) {
			v.push_back(ops);
		}
		return;
	}
	if (n == 0) return;

	for (int i = 0; i < 4; i++) {
		long long nx = n;
		if (op[i] == '*' && nx != 1 && nx <= 1e9) {
			nx *= nx;
		}
		else if (op[i] == '+' && nx <= 1e9) {
			nx += nx;
		}
		else if (op[i] == '-' && nx > 0) {
			nx = 0;
		}
		else if (op[i] == '/' && nx > 0 ) {
			nx = 1;
		}
		else continue;

		if (!m.count(nx) || m[nx] > ops.length()) {
			m[nx] = ops.length();
			ops.push_back(op[i]);
			solve(nx, ops);
			ops.pop_back();
		}
	}
}

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0 << "\n";
		return 0;
	}
	solve(s, "");
	if (v.empty()) cout << -1 << "\n";
	else {
		cout << v[0] << "\n";
	}
	return 0;
}
