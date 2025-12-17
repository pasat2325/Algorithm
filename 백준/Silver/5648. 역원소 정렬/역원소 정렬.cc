#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	vector<long long> v;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string num; cin >> num;
		reverse(num.begin(), num.end());
		
		long long nu = stoll(num);
		v.push_back(nu);
	}
	sort(v.begin(), v.end());
	for (long long nu : v) {
		cout << nu << "\n";
	}
}