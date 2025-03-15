#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	int s = 0;
	int e = vec.size() - 1;
	int anss = 0;
	int anse = 0;
	int diff = INT_MAX;
	while (s < e) {
		if (vec[s] + vec[e] == 0) {
			cout << vec[s] << " " << vec[e];
			return 0;
		}
		else if (vec[s] + vec[e] < 0) {
			if (abs(vec[s] + vec[e]) < diff) {
				diff = abs(vec[s] + vec[e]);
				anss = s;
				anse = e;
			}
			s++;
		}
		else if (vec[s] + vec[e] > 0) {
			if (abs(vec[s] + vec[e]) < diff) {
				diff = abs(vec[s] + vec[e]);
				anss = s;
				anse = e;
			}
			e--;
		}
	}
	cout << vec[anss] << " " << vec[anse];
	return 0;
}