#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	
	int s = 0;
	int e = n - 1;
	int p1 = 0, p2 = 0;
	bool back = true;

	for (int i = 0; i < n; i++) {
		if (back) {
			p1 += v[e];
			e--;
			back = false;
		}
		else {
			p2 += v[s];
			s++;
			back = true;
		}
	}
	cout << p2 << " " << p1;
}