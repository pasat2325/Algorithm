#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v(100'000);
int main() {
	int n; cin >> n;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[i] = { x,y };
		total += (long long)y;
	}
	sort(v.begin(), v.begin() + n);

	long long cur = 0;
	for (int i = 0; i < n; i++) {
		cur += (long long)v[i].second;
		if (cur >= (total + 1) / 2) {
			cout << v[i].first << "\n";
			return 0;
		}
	}

}