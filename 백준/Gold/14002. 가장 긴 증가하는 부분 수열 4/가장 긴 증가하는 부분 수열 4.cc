#include <iostream>
#include <vector>
using namespace std;
int arr[1000000];
int dp[1000000];
int parent[1000000];
int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) parent[i] = i;
	dp[0] = 0;

	int ml = 0;
	int mi = 0;
	for (int i = 1; i < n; i++) {
		int t = -1;
		int g = i;
 		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				if (dp[j] > t) {
					t = dp[j];
					g = j;
				}

			}
		}
		dp[i] = t + 1;
		parent[i] = g;
		if (dp[i] > ml) {
			ml = dp[i];
			mi = i;
		}
	}

	vector<int> v;
	while (true) {
		if (parent[mi] == mi) {
			v.push_back(arr[mi]);
			break;
		}
		v.push_back(arr[mi]);
		mi = parent[mi];
	}
	cout << ml + 1 << "\n";
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
}