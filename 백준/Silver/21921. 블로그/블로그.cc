#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, x; cin >> n >> x;
	int* guests = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		int g; cin >> g;
		if (i == 0)
			guests[i] = g;
		else guests[i] = g + guests[i - 1];
	}
	int ans1 = 0;
	int ans2 = 1;
	for (int i = 0; i <= n - x; i++) {
		int j = i + x - 1;
		int temp;
		if (i == 0) {
			temp = guests[j];
		}
		else temp = guests[j] - guests[i - 1];

		if (ans1 <= temp) {
			if (ans1 == temp) {
				ans2++;
			}
			else {
				ans2 = 1;
				ans1 = temp;
			}
		}
	}
	if (ans1 == 0) cout << "SAD";
	else {
		cout << ans1 << "\n" << ans2;
	}
	
}