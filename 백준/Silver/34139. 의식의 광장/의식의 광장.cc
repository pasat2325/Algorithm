#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<long long, long long>, int>> vec;
vector<int> how_far(200'001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, n;
	cin >> h >> n;

	for (int i = 1; i <= n; i++) {
		int r, c; cin >> r >> c;
		vec.push_back({ { c,r }, i });
	}
	sort(vec.begin(), vec.end());

	//for (auto i : vec) cout << i.first.first << " " << i.first.second << "\n";

	for (int i = 0; i < n; i++) {
		how_far[vec[i].second] = i + 1;
	}


	cout << "YES\n";
	for (int i = 1; i <= n; i++) cout << how_far[i] << " ";
}