#include <iostream>
#include <vector>
using namespace std;
char arr[4] = { 'u','d','r','l' };
int ans = 0;
int n;

void printMap(vector<vector<int>> map) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
vector<vector<int>> move(vector<vector<int>> map, char d) {
	if (d == 'u') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nx = i - 1;
				int ny = j;
				if (nx >= 0 && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (nx == 0) break;
						nx--;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx + 1][ny] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int combx = i + 1;
				int comby = j;
				if (combx < n) {
					if (map[combx][comby] == map[i][j]) {
						map[i][j] *= 2;
						map[combx][comby] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nx = i - 1;
				int ny = j;
				if (nx >= 0 && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (nx == 0) break;
						nx--;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx + 1][ny] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
	else if (d == 'd') {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				int nx = i + 1;
				int ny = j;
				if (nx < n && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (nx == n - 1) break;
						nx++;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					} 
					else {
						map[nx - 1][ny] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				int combx = i - 1;
				int comby = j;
				if (combx >= 0) {
					if (map[combx][comby] == map[i][j]) {
						map[i][j] *= 2;
						map[combx][comby] = 0;
					}
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				int nx = i + 1;
				int ny = j;
				if (nx < n && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (nx == n - 1) break;
						nx++;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx - 1][ny] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
	}
	else if (d == 'l') {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nx = i;
				int ny = j - 1;
				if (ny >= 0 && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (ny == 0) break;
						ny--;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx][ny + 1] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int combx = i;
				int comby = j + 1;
				if (comby < n) {
					if (map[combx][comby] == map[i][j]) {
						map[i][j] *= 2;
						map[combx][comby] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nx = i;
				int ny = j - 1;
				if (ny >= 0 && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (ny == 0) break;
						ny--;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx][ny + 1] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
	}
	else{
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				int nx = i;
				int ny = j + 1;
				if (ny < n && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (ny == n - 1) break;
						ny++;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx][ny - 1] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				int combx = i;
				int comby = j - 1;
				if (comby >= 0) {
					if (map[combx][comby] == map[i][j]) {
						map[i][j] *= 2;
						map[combx][comby] = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				int nx = i;
				int ny = j + 1;
				if (ny < n && map[nx][ny] == 0) {
					while (map[nx][ny] == 0) {
						if (ny == n - 1) break;
						ny++;
					}
					if (map[nx][ny] == 0) {
						map[nx][ny] = map[i][j];
						map[i][j] = 0;
					}
					else {
						map[nx][ny - 1] = map[i][j];
						map[i][j] = 0;
					}

				}
			}
		}
	}
	return map;
}
int findMax(vector<vector<int>> map) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = map[i][j] > temp ? map[i][j] : temp;
		}
	}
	return temp;
}

void rc(int depth, vector<vector<int>> map) {
	if (depth > 4) {
		int temp = findMax(map);
		ans = temp > ans ? temp : ans;
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> moved_map = move(map, arr[i]);
		/*
		cout << "==================================" << "\n";
		cout << "direction == " << arr[i] << "\n";
		printMap(moved_map);
		cout << "==================================" << "\n";\
		*/
		rc(depth + 1, moved_map);
		
	}
}
int main() {
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	rc(0, map);
	cout << ans;
}