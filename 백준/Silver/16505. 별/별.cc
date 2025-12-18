#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> v(2000, vector<char>(2000));

void solve(int x, int y, int depth) {
	if (depth == 0) {
		v[x][y] = '*';
		return;
	}

	int d = pow(2, depth - 1);
	solve(x, y, depth - 1);
	solve(x, y + d, depth - 1);
	solve(x + d, y, depth - 1);

}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int n; cin >> n;
	solve(0, 0, n);
	int len = pow(2, n);

	int row = 0;
	while (len >= 1) {
		for (int col = 0; col < len; col++) {
			if (v[row][col] != '*') cout << " ";
			else cout << "*";
		}
		cout << "\n";
		len -= 1;
		row += 1;
	}
}