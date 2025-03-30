#include <iostream>
#include <map>
#include <limits.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	map<long long, int> m;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		m[x]++;
	}

	int mx = 0;
	long long ans = 0;
	map<long long, int> ::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		if (i->second > mx) {
			ans = i->first;
			mx = i->second;
		}
		else if (i->second == mx) {
			ans = ans > i->first ? i->first : ans;
		}
	}
	cout << ans;

}