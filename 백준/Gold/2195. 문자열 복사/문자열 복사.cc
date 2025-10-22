#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string S, P;
	cin >> S >> P;

	int ans = 0;
	bool copied[1001] = { false, };
	for (int i = 0; i < P.length(); i++) {
		if (copied[i]) continue;
		ans++;
		for (int j = 0; j < S.length(); j++) {
			int k = 0;
			while (P[i + k] == S[j + k]) {
				copied[i + k] = true;
				k++;
			}
		}
	}
	cout << ans;
}