#include <iostream>
#include <vector>
using namespace std;


int N, M, T;
vector<vector<int>>circle(51, vector<int>(51));
vector<vector<bool>>delc(51, vector<bool>(51));

int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> circle[j][i];
		}
	}
	while (T--) {
		int x, d, k; cin >> x >> d >> k;
		while (k--) {

			for (int i = 0; i < M; i++) {
				fill(delc[i].begin(), delc[i].begin() + N, false);
			}

			for (int i = 0; i < N; i++) {
				int cur = i + 1;

				if (cur % x != 0) continue;

				if (d == 0) {
					int prev = circle[0][i];
					for (int j = 1; j <= M; j++) {
						int next_idx = j % M;

						int next = circle[next_idx][i];
						circle[next_idx][i] = prev;
						prev = next;
					}
				}
				else {
					int prev = circle[M - 1][i];
					for (int j = M - 2; j >= -1; j--) {
						int next_idx = (j + M) % M;

						int next = circle[next_idx][i];
						circle[next_idx][i] = prev;
						prev = next;
					}
				}
			}
		}

		bool del = false;
		// 원판 대 원판 인접 수 지우기
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N - 1; j++) {
				if (circle[i][j] == 0 || circle[i][j + 1] == 0) continue;

				if (circle[i][j] == circle[i][j + 1]) {
					delc[i][j] = 1;
					delc[i][j + 1]= 1;
					del = true;
				}
			}
		}
		// 원판 내부 인접 수 지우기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[j][i] == 0) continue;
				int next_idx = (j + 1) % M;

				if (circle[j][i] == circle[next_idx][i]) {
					delc[j][i] = 1;
					delc[next_idx][i] = 1;
					del = true;
				}
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (delc[i][j]) circle[i][j] = 0;
			}
		}

		if (del) continue;

		int sum = 0;
		int cnt = 0;

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				sum += circle[i][j];
				if (circle[i][j] > 0) cnt++;
			}
		}
		if (cnt == 0) continue;
		float avg = 0;
		avg = (float)sum / (float)cnt;
		
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (circle[i][j] == 0) continue;

				if ((float)circle[i][j] < avg) circle[i][j]++;
				else if ((float)circle[i][j] > avg) circle[i][j]--;
			}
		}
	
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			ans += circle[i][j];
		}
	}
	cout << ans;
}