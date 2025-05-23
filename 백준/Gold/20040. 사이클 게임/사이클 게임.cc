/*
사이클 판별 -> union find

연결하려는 두 점이 서로 같은 집합이라면 사이클을 생성한다.

*/
#include <iostream>
using namespace std;
int parent[500000];
int find_root(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_root(parent[x]);
}
bool is_same_set(int x, int y) {
	int rx = find_root(x);
	int ry = find_root(y);
	if (rx == ry) return true;
	parent[ry] = rx;
	return false;
}

int main() {
	int n, m;// n개의 점, m번째 차례
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) parent[i] = i;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (is_same_set(x, y)) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}