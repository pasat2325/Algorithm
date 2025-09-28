#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, j, s, h, k; cin >> n >> j >> s >> h >> k;
	vector<vector<char>>M (3, vector<char>(n));

	for (int i = 0; i < 3; i++) {
		for (int jj = 0; jj < n; jj++) {
			cin >> M[i][jj];
		}
	}

	int H = 0, L= 0, U =0; // 높,낮,상
	for (int i = 0; i < n; i++) {
		if (M[0][i] == 'v') {
			U += 1;
		}
		else if (M[1][i] == '^') {
			H += 1;
		}
		else if (M[2][i] == '^') {
			L += 1;
		}
	}
	
	h -= (U - min(s, U)) * k;

	int remainj = j - L;

	if (remainj >= 0) {
		h -= max(0, H - remainj / 2) * k;
	}
	else {
		h -= -remainj * k;
		h -= H * k;
	}
	if (h <= 0) cout << -1;
	else cout << h;

}