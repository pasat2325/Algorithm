#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	long long min_val = LLONG_MAX;
	int si = 0, ei= 0, in = 0;

	for (int i = 0; i < n; i++) {
		int s = 0, e = n - 1;
		long long val = 0;
		while (s < e) {
			if (s == i) { s++; continue; }
			if (e == i) { e--; continue; }
			val = v[i] + v[s] + v[e];
			if (abs(val) >= min_val) {
				// 차이를 더 줄여주는 조합을 찾아야 함.
				long long t1 = val - v[s] + v[s + 1];
				long long t2 = val - v[e] + v[e - 1];
				if (abs(t1) > abs(t2)) e--;
				else s++;
			}
			else { 
				min_val = abs(val);
				si = s, ei = e, in = i;
			}
		}
	}
	int ans[3] = {v[si],v[ei],v[in]};
	sort(ans, ans+ 3);
	for (auto i : ans) cout << i << " ";
}