#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int>>vec(201);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		vec[i].push_back(x);
		vec[i].push_back(y);
		vec[i].push_back(z);
	}
	for (int i = 0; i < n; i++) {
		int score = 0;
		for (int j = 0; j < 3; j++) {
			int cnt = 0;
			for (int k = 0; k < n; k++) {
				if (vec[i][j] == vec[k][j]) cnt++;
			}
			if (cnt == 1) score += vec[i][j];
		}
		cout << score << "\n";
	}
}