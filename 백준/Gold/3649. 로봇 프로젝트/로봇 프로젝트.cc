#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, n;
	while (cin >> x >> n) {
		vector<int>v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int st = 0, lt = v.size() - 1;
		if (st == lt) {
			cout << "danger" << "\n";
			continue;
		}
		int t = x * 10000000;
		bool flag = false;
		while (st < lt) {
			int sum = v[st] + v[lt];
			if (sum == t) {
				cout << "yes " << v[st] << " " << v[lt] << "\n";
				break;
			}
			else if (sum > t) lt--;
			else if (sum < t) st++;
		}
		if (st >= lt) cout << "danger" << "\n";
	}
}
