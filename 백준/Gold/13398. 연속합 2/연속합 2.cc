#include <iostream>
using namespace std;
int dp1[100000];
int dp2[100000];
int arr[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, lmx, gmx;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];


	if (n == 1) {
		cout << arr[0];
		return 0 ;
	}
	// dp1
	lmx = arr[0];
	dp1[0] = lmx;
	for (int i = 1; i < n; i++) {
		lmx = max(lmx + arr[i], arr[i]);
		dp1[i] = lmx;
	}
	//dp2
	lmx = arr[n - 1];
	dp2[n - 1] = lmx;
	for (int i = n - 2; i >= 0; i--) {
		lmx = max(lmx + arr[i], arr[i]);
		dp2[i] = lmx;
	}

	gmx = dp1[0];
	for (int i = 1; i < n; i++) {
		gmx = max(gmx, dp1[i]);
	}

	for (int i = 1; i < n - 1; i++) {
		gmx = max(gmx, dp1[i - 1] + dp2[i + 1]);
	}
	gmx = max(gmx, dp2[1]);
	gmx = max(gmx, dp1[n - 2]);
	cout << gmx;


}