#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> org(n);
	vector<int> sorted_org(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		org[i] = sorted_org[i] = x;
	}
	sort(sorted_org.begin(), sorted_org.end());

	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!used[j] && org[i] == sorted_org[j]) {
				cout << j << " ";
				used[j] = true; 
				break;
			}
		}
	}
	
}