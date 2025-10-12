#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int L = 0, R = 0;


	vector<int> index(100'001, -1);
	long long ans = 0;
	while (true) {
		if (R == n) break;
		int cur = v[R];

		if (index[cur] >= L) {
			L = index[cur] + 1;
		}
		ans += R - L + 1;
		index[cur] = R;
		R++;
	}
	cout << ans;
}