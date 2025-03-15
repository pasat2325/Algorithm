#include <iostream>
using namespace std;
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int mn;
	int mx;
	mx = n - m * k;
	if (mx < 0) mx = 0;
	if (k == 1) mn = n - 1;
	else mn = n - m * (k - 1) - 1;
	cout << mx <<" "<< mn;

}