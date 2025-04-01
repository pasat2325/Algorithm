#include <iostream>
#include <limits.h>
#include <stdlib.h>
using namespace std;
int main() {
	float k, p, x;
	cin >> k >> p >> x;
	float minv = INT_MAX;
	for (int i = 1; i <= 10000; i++) {
		float d = k / i;
		float v = i * x + d * p;
		if (v < minv) minv = v;
	}
	printf("%.3f", minv);
}