#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

int main() {
	int n; cin >> n;
	vector<pair<int,int>> flowers(n);

	for (int i = 0; i < n; i++) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;

		int d = x * 100 + y;
		int dd = xx * 100 + yy;

		flowers[i] = { d,dd }; // 피는 날, 지는 날
	}

	sort(flowers.begin(), flowers.end(), comp);

	int latest = 301;
	int res = 0;
	int idx = 0;

	while (latest <= 1130) {
		int max_end = 0;
		bool found = false;

		while (idx < n && flowers[idx].first <= latest) {
			max_end = max(max_end, flowers[idx].second);
			found = true;
			idx++;
		}

		if (!found || max_end <= latest) {
			cout << 0;
			return 0;
		}

		latest = max_end;
		res++;
	}
	cout << res;

}