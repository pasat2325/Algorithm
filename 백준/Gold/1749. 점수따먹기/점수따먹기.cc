#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> input_2D(201, vector<int>(201, 0));
vector<vector<ll>> prefix_sum_2D(201, vector<ll>(201, 0));

int main() {
	int N, M; cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input_2D[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			prefix_sum_2D[i][j] = (long long)input_2D[i][j] + prefix_sum_2D[i - 1][j] + prefix_sum_2D[i][j - 1] - prefix_sum_2D[i - 1][j - 1];
		}
	}

	long long ans = -1e10;

	for (int i = 1; i <= N; i++) {
		vector<long long> arr(M + 1, 0);
		for (int j = i; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				arr[k] += input_2D[j][k];
			}
			long long temp = 0;
			for (int k = 1; k <= M; k++) {
				if (temp < 0) temp = 0;
				temp += arr[k];
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
}