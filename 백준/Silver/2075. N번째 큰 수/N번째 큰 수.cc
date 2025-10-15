#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_NN = 1500 * 1500;
int arr[MAX_NN];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n * n, greater<>());
	cout << arr[n- 1];

}