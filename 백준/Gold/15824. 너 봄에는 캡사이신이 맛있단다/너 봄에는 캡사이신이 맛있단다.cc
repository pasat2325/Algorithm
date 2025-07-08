#include <iostream>
#include <algorithm>
#define MAX_N 300000
#define mod 1000000007
using namespace std;
int n, s[MAX_N];
long long menu[MAX_N];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> menu[i];
	sort(menu, menu + n);
	int temp = 1;
	for (int i = 0; i < n; i++) {
		s[i] = temp - 1;
		temp *= 2;
		temp %= mod;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (s[i] * ((menu[i] - menu[n - 1 - i]) % mod))% mod;
		ans %= mod;
	}
	cout << ans;

}