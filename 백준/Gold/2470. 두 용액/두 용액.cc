#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
int arr[100000];
bool compare(int a, int b) {
	return abs(a) < abs(b);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n,compare);

	int diff = INT_MAX;
	int ans1, ans2;
	for (int i = 0; i < n - 1; i++) {
		int temp = abs(arr[i] + arr[i + 1]);
		if (temp < diff) {
			diff = temp;
			ans1 = arr[i];
			ans2 = arr[i + 1];
		}
	}
	if (ans1 > ans2) cout << ans2 << " " << ans1;
	else cout << ans1 << " " << ans2;
}