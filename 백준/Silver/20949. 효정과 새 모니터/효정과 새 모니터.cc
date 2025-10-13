#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n; cin >> n;
	vector<pair<int,int>> v;
	int idx = 1;
	while (n--) {
		int a, b; cin >> a >> b;
		int c = a * a + b * b;
		v.push_back({ -c, idx++ });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i.second << "\n";
	}
	return 0;
}