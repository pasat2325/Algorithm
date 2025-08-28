#include <iostream>
#include <cmath>
using namespace std;

bool is_square(int n) {
	int r = (int)sqrt(n);
	return r * r == n;
}

int main() {
	int n, m;
	cin >> n >> m;

	int map[9][9];
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = m - 1; j >= 0; j--) {
			map[i][j] = str[j] - '0';
		}
	}

	int ans = 0;
	bool s = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int dx = -(n - 1); dx < n; dx++) {
				for (int dy = -(m - 1); dy < m; dy++) {
					int num = 0;
					if(dx == 0 && dy == 0) {
						num += map[i][j];
						if (is_square(num)) {
							s = true;
							ans = max(ans, num);
						}
					}
					else {
						int x = i;  int y = j;
						while (x >= 0 && y >= 0 && x < n && y < m) {
							num *= 10;
							num += map[x][y];
							if (is_square(num)) {
								s = true;
								ans = max(ans, num);
							}
							x += dx;
							y += dy;
						}
					}

				}
			}
		}
	}
	if (s) cout << ans << "\n";
	else cout << -1 <<"\n";
	
}
