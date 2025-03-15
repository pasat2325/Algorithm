#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>
using namespace std;
int n;
vector<int> v;

pair<int,int> bs(int low, int high, int t) {
	int lt = -1;
	int diff = INT_MAX;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int temp = v[mid] + t;
		if (temp == 0) return { 0,v[mid] };
		else if (temp < 0) {
			if (diff > abs(temp)) {
				diff = abs(temp);
				lt = mid;
			}
			low = mid + 1;
		}
		else {
			if (diff > abs(temp)) {
				diff = abs(temp);
				lt = mid;
			}
			high = mid - 1;
		}
	}
	return { diff ,v[lt] };
}
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int diff= INT_MAX;
	int s, e;
	vector<pair<int, int>> vp;
	for (int i = 0; i < n - 1; i++) {
		int t = v[i];
		pair<int, int> temp = bs(i + 1, n - 1, t);
		int temp_diff = temp.first;
		int ltv = temp.second;
		if (diff > temp_diff) {
			diff = temp_diff;
			s = v[i];
			e = ltv;
		}
	}
	cout << s << " " << e;
	
}