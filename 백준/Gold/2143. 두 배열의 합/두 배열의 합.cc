#include <iostream>
#include <map>
using namespace std;
int a_arr[1001];
int b_arr[1001];
int a_prefix[1001][1001];
int b_prefix[1001][1001];
map<int, int> M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a_arr[i];
	int m; cin >> m;
	for (int i = 1; i <= m; i++)
		cin >> b_arr[i];


	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == j)
				a_prefix[i][j] = a_arr[i];
			else {
				a_prefix[i][j] = a_prefix[i][j - 1] + a_arr[j];
			}
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			if (i == j)
				b_prefix[i][j] = b_arr[i];
			else {
				b_prefix[i][j] = b_prefix[i][j - 1] + b_arr[j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int temp = t - a_prefix[i][j];
			if (M.find(temp) == M.end()) {
				M.insert({ temp, 1 });
			}
			else M[temp]++;
		}
	}

	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m; j++) {
			ans += M[b_prefix[i][j]];
		}
	}
	cout << ans;
	
}