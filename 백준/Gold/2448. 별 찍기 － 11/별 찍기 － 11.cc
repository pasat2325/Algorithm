#include <iostream>
using namespace std;

char map[3100][7000];

void draw_triangle(int n, int x, int y) {
	if (n == 3) {
		map[x][y] = '*';
		
		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';

		for (int i = y - 2; i <= y + 2; i++) {
			map[x + 2][i] = '*';
		}

		return;
	}
	draw_triangle(n / 2, x, y);
	draw_triangle(n / 2, x + n / 2, y - n / 2 );
	draw_triangle(n / 2, x + n / 2, y + n / 2);


}

int main() {
	int n;
	cin >> n;
	draw_triangle(n, 0, n-1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (map[i][j] == '*') cout << map[i][j];
			else cout << ' ';
		}
		cout << "\n";
	}

}