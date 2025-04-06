#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
vector<pair<int,int>> emp;
int t;
// 스도쿠 규칙 확인
vector<bool> exist(int x, int y){
	vector<bool> check(9, false);
	for (int i = 0; i < 9; i++) {
		if (map[x][i]) check[map[x][i] - 1] = true;
	}
	for (int i = 0; i < 9; i++) {
		if (map[i][y]) check[map[i][y] - 1] = true;
	}

	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (map[i][j]) check[map[i][j] - 1] = true;
		}
	}
	return check;
}
void printMap() {
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void solve(int depth) {
	//printMap();
	if (depth == t) {
		printMap();
		exit(0);
	}
	int x = emp[depth].first;
	int y = emp[depth].second;
	vector<bool> check = exist(x, y);
	for (int i = 1; i <= 9; i++) {
		if (!check[i - 1]) {
			map[x][y] = i;
			solve(depth + 1);
			map[x][y] = 0;
		}
	}
}

int main() {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int x;
			cin >> x;
			map[i][j] = x;
			if (x == 0) emp.push_back({ i,j });
		}
	}
	t = emp.size();
	solve(0);
}