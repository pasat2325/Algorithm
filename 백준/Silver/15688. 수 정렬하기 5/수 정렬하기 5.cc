#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);

	vector<int> v(n);
	
	int index = 0;
	while (n--) {
		scanf("%d", &v[index++]);
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		printf("%d\n", i);
	}
}