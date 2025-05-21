#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
char op[4] = { '*', '+', '-', '/' };
int s, t;
string result;
map<long long, int> m;

void solve(long long n, string ops) {
	if (n == t) {
		result = ops;
		return;
	}
	if (n == 0) return;

	for (int i = 0; i < 4; i++) {
		long long nx = n;
		if (op[i] == '*' && nx != 1 && nx <= sqrt(1e9)) {
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
	if (result.empty()) cout << -1 << "\n";
	else {
		cout << result << "\n";
	}
	return 0;
}
