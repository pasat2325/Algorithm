// 카데인 dp
#include <iostream>
#include <vector>
using namespace std;
int dp[100000];
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	int gmx, lmx;
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			dp[0] = v[0];
			lmx = v[0];
			gmx = v[0];
		}
		else { 
			dp[i] = max(v[i], lmx + v[i]);
			lmx = dp[i];
			gmx = max(gmx, lmx);
		}
	}
	cout << gmx;
}