#include<iostream>
#include<cstring>
using namespace std;
const int MAX_N = 100'001;
int docking_position[MAX_N];

int find_pos(int x) {
	if (x == 0) return 0;
	if (docking_position[x] == x) return x;
	return docking_position[x] = find_pos(docking_position[x]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int g, p; cin >> g >> p;
	for (int i = 0; i <= g; i++) docking_position[i] = i;
	int res = 0;
	while (p--) {
		int range; cin >> range;
		int t = find_pos(range);
		if (t == 0) {
			cout << res;
			return 0;
		}
		res++;
		docking_position[t] = find_pos(t - 1);
	}
	cout << res;
	return 0;
}