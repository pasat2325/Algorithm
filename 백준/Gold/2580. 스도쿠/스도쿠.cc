#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
vector<pair<int,int>> emp;
int t;
// 스도쿠 규칙 확인
vector<bool> exist(int x, int y){
	vector<bool> check(9,false);

	for (int i = 0; i < 9; i++) {
		if (map[x][i]) check[map[x][i] - 1] = true;
	}
	for (int i = 0; i < 9; i++) {
		if (map[i][y]) check[map[i][y] - 1] = true;
	}
	int x1, x2, y1, y2;
	if (x <= 2) {
		if (y <= 2) {
			x1 = 0;
			x2 = 3;
			y1 = 0;
			y2 = 3;
		}
		else if (y <= 5) {
			x1 = 0;
			x2 = 3;
			y1 = 3;
			y2 = 6;
		}
		else {
			x1 = 0;
			x2 = 3;
			y1 = 6;
			y2 = 9;
		}
	}
	else if (x <= 5) {
		if (y <= 2) {
			x1 = 3;
			x2 = 6;
			y1 = 0;
			y2 = 3;
		}
		else if (y <= 5) {
			x1 = 3;
			x2 = 6;
			y1 = 3;
			y2 = 6;
		}
		else {
			x1 = 3;
			x2 = 6;
			y1 = 6;
			y2 = 9;
		}
	}
	else {
		if (y <= 2) {
			x1 = 6;
			x2 = 9;
			y1 = 0;
			y2 = 3;
		}
		else if (y <= 5) {
			x1 = 6;
			x2 = 9;
			y1 = 3;
			y2 = 6;
		}
		else {
			x1 = 6;
			x2 = 9;
			y1 = 6;
			y2 = 9;
		}
	}
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
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

	vector<bool> check = exist(emp[depth].first, emp[depth].second);
	for (int i = 1; i <= 9; i++) {
		if (!check[i - 1]) {
			map[emp[depth].first][emp[depth].second] = i;
			solve(depth + 1);
			map[emp[depth].first][emp[depth].second] = 0;
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