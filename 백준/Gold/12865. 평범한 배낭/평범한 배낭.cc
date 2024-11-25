#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int value[101][100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, w, v, k;

	vector<pair<int,int>> o;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> w >> v;
		o.push_back(make_pair(w, v));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (o[i-1].first > j) { //배낭에 넣을 수 없는 경우.
				value[i][j] = value[i-1][j];
			}
			else {
			
				value[i][j] = max(value[i - 1][j], value[i - 1][j - o[i-1].first] + o[i-1].second);
			}
		}
	}
	
	cout << value[n][k];

}