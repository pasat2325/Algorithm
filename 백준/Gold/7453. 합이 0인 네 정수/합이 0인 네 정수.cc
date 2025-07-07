#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	scanf("%d", &n);

	vector<int> a(n), b(n), c(n), d(n);

	for (int j = 0; j < n; j++) {
		int q, w, e, r;
		scanf("%d %d %d %d", &q, &w, &e, &r);
		a[j] = q; b[j] = w; c[j] = e; d[j] = r;
	}

	vector<int> ab;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = a[i] + b[j];
			ab.push_back(sum);
		}
	}
	
	sort(ab.begin(), ab.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = -(c[i] + d[j]);
			int low = lower_bound(ab.begin(), ab.end(), t) - ab.begin();
			int up = upper_bound(ab.begin(), ab.end(), t) - ab.begin();
			ans += up - low;
		}
	}

	printf("%lld", ans);
}