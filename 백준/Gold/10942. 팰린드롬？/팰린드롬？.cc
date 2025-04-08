#include <iostream>
using namespace std;
bool dp[2000][2000];
int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	int arr[2000];
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) dp[i][i] = true;
	for (int i = 0; i < n - 1; i++) {
		if(arr[i] == arr[i + 1]) dp[i][i + 1] = true;
	}
	//for (int i = 0; i < n - 2; i++) if (arr[i] == arr[i + 2]) dp[i][i + 2] = true;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 2; j < n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = true;
		}
	}
	int q,s,e;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> s >> e;
		if (dp[s - 1][e - 1]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	
}
