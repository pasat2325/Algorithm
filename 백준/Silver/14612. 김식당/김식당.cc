#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int,int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "order") {
			int n, t;
			cin >> n >> t;
			v.push_back({ n,t });
		}
		else if (cmd == "sort") {
			sort(v.begin(), v.end(), comp);
		}
		else if (cmd == "complete") {
			int n;
			cin >> n;
			v.erase(remove_if(v.begin(), v.end(), [&](auto& x) {
				return x.first == n;
			}), v.end());
		}

		if (v.empty()) cout << "sleep\n";
		else {
			for (auto& [table, time] : v)
				cout << table << " ";
			cout << "\n";
		}
	}
}