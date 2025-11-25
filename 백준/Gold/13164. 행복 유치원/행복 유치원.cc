#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> heights(n);
	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}
	sort(heights.begin(), heights.end());

	vector<int> dist(n - 1);
	for (int i = 0; i < n - 1; i++) {
		dist[i] = heights[i + 1] - heights[i];
	}
	sort(dist.begin(), dist.end());

	long long res = 0;
	for (int i = 0; i < n - k; i++) {
		res += dist[i];
	}
	cout << res;
}