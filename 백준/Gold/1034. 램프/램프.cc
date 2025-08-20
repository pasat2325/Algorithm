#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> rows;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		rows.push_back(row);
	}

	int k;
	cin >> k;

	map<string, int> map;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < m; j++) {
			if (rows[i][j] - '0' == 0) t++;
		}

		if (t <= k && ((k & 1 && t & 1) || (!(k & 1) && !(t & 1)))) {
			if (map.find(rows[i]) == map.end()) {
				map.insert({ rows[i], 1 });
			}
			else {
				map[rows[i]]++;
			}
		}
	}

	int ans = 0;
	for (auto i : map) {
		ans = max
		(ans, i.second);
	}
	cout << ans;

}