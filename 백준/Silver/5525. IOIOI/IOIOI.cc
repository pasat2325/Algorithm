#include <iostream>

using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m >> s;

	int ret = 0;

	for (int i = 0; i < m; i++) {
		int end = i;
		int a = 0;

		if (s[i] == 'I') {
			for (int j = i; j < m; j++) {
				if (j + 1 != s.size()) {
					if (s[j] == s[j + 1]) break;
					end = j + 1;
				}
			}
			int leng = end - i + 1;

			if (leng >= 2 * n + 1) {
				a = 1;
				while (leng - 2 * a >= 2 * n + 1) {
					a++;
				}
			}
		}
		ret += a;
		i = end;
	}

	cout << ret;
}