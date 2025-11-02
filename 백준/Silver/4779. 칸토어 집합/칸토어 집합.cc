/*
N이 주어졌을 때, 칸토어집합은 (N - 1) 칸토어 집합 2개가 N / 3 만큼의 공백을 두고 서로 떨어져 있는 형태이다.

*/
#include <iostream>
#include <cmath>
using namespace std;

void cantor(int n) {
	int s = pow(3, n - 1);
	if (n == 0) {
		cout << '-';
		return;
	}
	else {
		cantor(n - 1);
		for (int i = 0; i < s; i++) cout << ' ';
		cantor(n - 1);
	}
	return;
}
int main() {
	int n;
	while (cin >> n) {
		cantor(n);
		cout << '\n';
	}
}