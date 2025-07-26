#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double n = a / b * c;
	double m = a * b / c;
	int mx = max(n, m);
	cout << mx;
}