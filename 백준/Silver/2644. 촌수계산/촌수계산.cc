#include <iostream>
#include <vector>
using namespace std;
vector<int> parents(101);
vector<bool> visited(101);

int main() {
	int n; cin >> n;
	int a, b; cin >> a >> b;
	int m; cin >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		// x 부모, y 자식
		parents[y] = x;
	}
	int temp = a;
	while (true) {
		visited[temp] = true;
		if (parents[temp] == 0) {
			break;
		}
		temp = parents[temp];
	}

	int r = -1;
	temp = b;
	while (true) {
		if (visited[temp]) {
			r = temp;
			break;
		}
		if (parents[temp] == 0) {
			break;
		}
		temp = parents[temp];

	}
	if (r == -1) cout << r << "\n";
	else {
		int z = 0;
		temp = a;
		while (true) {
			if (temp == r) break;
			z++;
			temp = parents[temp];
		}
		int zz = 0;
		temp = b;
		while (true) {
			if (temp == r) break;
			zz++;
			temp = parents[temp];
		}
		cout << z + zz;
	}
}