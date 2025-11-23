#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<int> mm;
	for (int i = 0; i < n; i++) {
		int P, L; cin >> P >> L;
		vector<int> v(P);
		
		for (int j = 0; j < P; j++) {
			cin >> v[j];
		}

		if (L > P) {
			mm.push_back(1);
		}
		else {
			sort(v.begin(), v.end());

			if (L == P) {
				mm.push_back(v[0]);
			}
			
			else if (L < P) {
				mm.push_back(v[P - L]);
			}
		}
	}
	sort(mm.begin(), mm.end());
	int to = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (to + mm[i] > m) break;
		to += mm[i];
		ans++;
	}
	cout << ans;
}