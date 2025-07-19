#include <iostream>
#include <vector>
using namespace std;
int n;

void solve(vector<int> v, int d) {
	if (d == n - 1) {
		
		int sum = 0;
		int tmp = 0;
		for (int i = n; i >= 1; i--) {
			if (i == 1) {
				if (tmp) {
					int x = i;
					while (x < tmp) {
						x *= 10;
					}
					sum += x + tmp;
					tmp = 0;
				}
				else sum += i;
				break;
			}
			if (v[i - 2] == 1) {
				if (tmp) {
					int x = i;
					while (x < tmp) {
						x *= 10;
					}
					sum += x + tmp;
					tmp = 0;
				}
				else
					sum += i;
			}
			else if (v[i - 2] == 2) {
				if (tmp) {
					int x = i;
					while (x < tmp) {
						x *= 10;
					}
					sum -= x + tmp;
					tmp = 0;
				}
				else
					sum -= i;
			}
			else {
				if (tmp) {
					int x = i;
					while (x < tmp) {
						x *= 10;
					}
					tmp = x + tmp;
				}
				else tmp = i;
			}
		}
		if (sum== 0) {
			cout << 1;
			for (int i = 2; i <= n; i++) {
				char c;
				if (v[i - 2] == 1) c = '+';
				else if (v[i - 2] == 2) c = '-';
				else c = ' ';
				cout << c << i;
			}
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		v.push_back(i);
		solve(v, d + 1);
		v.pop_back();
	}
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> v;
		solve(v, 0);
		cout << "\n";

	}
}