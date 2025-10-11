#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int max_n = 10'000'000;
double arr[max_n];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < 7; i++) {
		printf("%.3f\n", arr[i]);
	}
}