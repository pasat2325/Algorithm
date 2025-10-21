#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, m; cin >> n >> m;
	vector<int> vec(m);
	for (int i = 0; i < m; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int max_rev = 0;
	int max_cost = 0;
	for (int i = 0; i < m; i++) {
		int val = vec[i];
		int how_many = min(m - i, n);
		int rev = val * how_many;
		
		if (rev > max_rev) {
			max_rev = rev;
			max_cost = val;
		}
	}
	cout << max_cost << " " << max_rev << "\n";
	return 0;
}