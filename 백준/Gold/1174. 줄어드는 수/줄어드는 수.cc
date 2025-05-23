#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> v;

void solve(int prev_digit, long long num, int depth) {

	for (int i = 0; i <= 9; i++) {
		if (depth == 0) {
			long long temp = num + i;
			v.push_back(temp);
			solve(i, temp * 10, depth + 1);
		}
		else {
			if (i < prev_digit) {
				long long temp = num + i;
				v.push_back(temp);
				solve(i, temp * 10, depth + 1);
			}
			else return;
		}
	}
}
int main() {
	solve(10, 0, 0);
	sort(v.begin(), v.end());
	int n;
	cin >> n;
	if (n > v.size()) cout << -1;
	else cout << v[n - 1];
}