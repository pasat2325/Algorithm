#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, s;
	cin >> n >> s;
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	int start = 0, end = 0;
	int sum = vec[0];
	int len = n + 1;
	while (start <= end && end < n) {
		if (sum < s) {
			end++;
			//if (end == n) break;
			sum += vec[end];
		}
		else if (sum >= s) {
			len = len > end - start + 1 ? end - start + 1 : len;
			sum -= vec[start];
			start++;
		}
	}
	if (len == n + 1) cout << 0;
	else cout << len;
}