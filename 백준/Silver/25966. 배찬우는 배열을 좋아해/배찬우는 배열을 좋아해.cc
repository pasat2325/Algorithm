#include <iostream>
using namespace std;
int arr[3000][3000];
int row_point[3000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, q; cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		row_point[i] = i;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (q--) {
		int d; cin >> d;
		if (d) {
			int i, j; cin >> i >> j;
			int temp = row_point[i];
			row_point[i] = row_point[j];
			row_point[j] = temp;
		}
		else {
			int i, j, k; cin >> i >> j >> k;
			arr[row_point[i]][j] = k;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[row_point[i]][j] << " ";
		}
		cout << "\n";
	}
}