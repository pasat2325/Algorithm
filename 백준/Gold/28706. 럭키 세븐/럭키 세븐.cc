#include <iostream>
#include <cstring>
using namespace std;

bool dp[2][7]; // [이전/현재][0~6 나머지] 

int calc_remain(char op, int num, int r) {
	if (op == '+') {
		return (num + r) % 7;
	}
	else return (num * r) % 7;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		char op1, op2; int num1, num2;

		memset(dp, false, sizeof(dp));
		
		dp[0][1] = true;

		for (int i = 1; i <= N; i++) {
			cin >> op1 >> num1 >> op2 >> num2;

			int current = i % 2;
			int prev = (i - 1) % 2;

			memset(dp[current], false, sizeof(dp[current]));

			for (int j = 0; j < 7; j++) {
				if (dp[prev][j] == true) {
					dp[current][calc_remain(op1, num1, j)] = true;
					dp[current][calc_remain(op2, num2, j)] = true;
				}
			}
		}
		if (dp[N % 2][0] == true) {
			cout << "LUCKY\n";
		}
		else cout << "UNLUCKY\n";
	}
}