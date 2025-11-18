#include <iostream>
#include <cstring>
using namespace std;
int grid[100][100];
bool used[100][100];
int main() {
	int N, L; cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}

	// 가로 길 확인

	int hor = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N - 1) {
				hor++;
				break;
			}

			int ch = grid[i][j];
			int nh = grid[i][j + 1];

			if (ch == nh) continue;
			// 내리막
			else if (ch == nh + 1) {
				if (j + L >= N) break; // 범위가 벗어나면 경사로를 만들 수 없음

				// 높이가 모두 같고, 다른 경사로가 없는지 확인
				int temp_idx = j + 1;
				bool can = true;
				for (int k = 0; k < L; k++) {
					if (used[i][temp_idx]) {
						can = false;
					}

					if (grid[i][temp_idx] != nh) {
						can = false;
					}
					temp_idx++;
				}
				if (!can) break; 
				temp_idx = j + 1;
				for (int k = 0; k < L; k++) {
					used[i][temp_idx++] = true;
				}
			}
			// 오르막
			else if (ch == nh - 1) {
				if (j - L + 1 < 0) break; // 범위가 벗어나면 경사로를 만들 수 없음

				// 높이가 모두 같고, 다른 경사로가 없는지 확인
				int temp_idx = j - L + 1;
				bool can = true;
				for (int k = 0; k < L; k++) {
					if (used[i][temp_idx]) {
						can = false;
					}

					if (grid[i][temp_idx] != ch) {
						can = false;
					}
					temp_idx++;
				}
				if (!can) break;
				temp_idx = j - L + 1;
				for (int k = 0; k < L; k++) {
					used[i][temp_idx++] = true;
				}
			}
			// 높이차가 2이상이면 지날 수 없음
			else {
				break;
			}
		}
	}

	memset(used, false, sizeof(used));
	// 세로 길 확인
	int ver = 0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (i == N - 1) {
				ver++;
				break;
			}

			int ch = grid[i][j];
			int nh = grid[i + 1][j];

			if (ch == nh) continue;
			// 내리막
			else if (ch == nh + 1) {
				if (i + L >= N) break; // 범위가 벗어나면 경사로를 만들 수 없음

				// 높이가 모두 같고, 다른 경사로가 없는지 확인
				int temp_idx = i + 1;
				bool can = true;
				for (int k = 0; k < L; k++) {
					if (used[temp_idx][j]) {
						can = false;
					}

					if (grid[temp_idx][j] != nh) {
						can = false;
					}
					temp_idx++;
				}
				if (!can) break;
				temp_idx = i + 1;
				for (int k = 0; k < L; k++) {
					used[temp_idx++][j] = true;
				}
			}
			// 오르막
			else if (ch == nh - 1) {
				if (i - L + 1 < 0) break; // 범위가 벗어나면 경사로를 만들 수 없음

				// 높이가 모두 같고, 다른 경사로가 없는지 확인
				int temp_idx = i - L + 1;
				bool can = true;
				for (int k = 0; k < L; k++) {
					if (used[temp_idx][j]) {
						can = false;
					}

					if (grid[temp_idx][j] != ch) {
						can = false;
					}
					temp_idx++;
				}
				if (!can) break;
				temp_idx = i - L + 1;
				for (int k = 0; k < L; k++) {
					used[temp_idx++][j] = true;
				}
			}
			// 높이차가 2이상이면 지날 수 없음
			else {
				break;
			}
		}
	}
	cout << hor + ver << "\n";

}