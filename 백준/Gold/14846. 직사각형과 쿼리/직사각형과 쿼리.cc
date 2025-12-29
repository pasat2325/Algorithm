#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input_2D(301, vector<int>(301));
vector<vector<vector<int>>> prefix_sum_3D(301, vector<vector<int>> (301, vector<int> (11, 0)));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> input_2D[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 10; k++) {
				prefix_sum_3D[i][j][k] = prefix_sum_3D[i - 1][j][k] + prefix_sum_3D[i][j - 1][k] - prefix_sum_3D[i - 1][j - 1][k];
				if (input_2D[i][j] == k) prefix_sum_3D[i][j][k]++;
			}
		}
	}

	// query
	int Q; cin >> Q;
	vector<int> total(11, 0);

	while (Q--) {
		int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

		for (int i = 1; i <= 10; i++) {
			total[i] = prefix_sum_3D[r2][c2][i];

			total[i] -= prefix_sum_3D[r1 - 1][c2][i];
			total[i] -= prefix_sum_3D[r2][c1 - 1][i];
			total[i] += prefix_sum_3D[r1 - 1][c1 - 1][i];
		}

		int cnt = 0;
		for (int i = 1; i <= 10; i++) {
			if (total[i] > 0) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}