#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 200'001;

bool dp[MAX_N][7]; // N번째 턴까지 수행하였을 때, {0 ~ 6} 나머지가 존재하는지 체크 

int calc_remain(char op, int num, int r) {
	if (op == '+') {
		return (num + r) % 7;
	}
	else return (num * r) % 7;
}


int main() {
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		char op1, op2; int num1, num2;

		memset(dp, false, MAX_N * 7);
		
		dp[0][1] = true;

		for (int i = 1; i <= N; i++) {
			cin >> op1 >> num1 >> op2 >> num2;

			for (int j = 0; j < 7; j++) {
				if (dp[i - 1][j] == true) {
					dp[i][calc_remain(op1, num1, j)] = true;
					dp[i][calc_remain(op2, num2, j)] = true;
				}
			}
		}
		if (dp[N][0] == true) {
			cout << "LUCKY\n";
		}
		else cout << "UNLUCKY\n";
	}
}