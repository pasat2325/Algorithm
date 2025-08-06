#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int k, n, m;
	cin >> k >> n >> m;
	cout << (k * n < m ? 0 : k * n - m);
}