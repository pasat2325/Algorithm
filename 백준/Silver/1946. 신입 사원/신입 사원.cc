#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<pair<int, int>> vec(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vec[i] = { x,y };
		}
		sort(vec.begin(), vec.end());
		if (vec[0].first == vec[0].second) {
			cout << 1 << "\n";
		}
		else {
			int ans = 0;
			int min_meeting = vec[0].second;
			for (int i = 1; i < n; i++) {
				if (vec[i].second < min_meeting) {
					min_meeting = vec[i].second;
					ans++;
				}
			}
			cout << ans + 1<< "\n";
		}
	}
}