#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	while (1) {
		int n; cin >> n;
		vector<int> v;
		if (n == -1) break;

		int S = 1;
		for (int i = 2; i * i <= n; i++) {
			
			if (n % i == 0) {
				
				S += i;
				v.push_back(i);

				if (n / i != i) {
					S += n / i;
					v.push_back(n / i);
				}
			}
		}
		if (S == n) {
			sort(v.begin(), v.end());
			cout << n << " = 1 + ";
			for (int i = 0; i < v.size(); i++) {
				if (i != v.size() - 1) cout << v[i] << " + ";
				else cout << v[i] << "\n";
			}
		}
		else cout << n << " is NOT perfect.\n";
	}

}