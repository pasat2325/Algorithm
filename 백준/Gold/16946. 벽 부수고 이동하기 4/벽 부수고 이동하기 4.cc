#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int grid[1000][1000];
int parent[1'000'001];
int set_size[1'000'001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int used_set[4];

void make_set(int idx) {
	parent[idx] = idx;
	set_size[idx] = 1;
}

int find_root(int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = find_root(parent[idx]);
}

void unite(int a, int b) {
	int a_root = find_root(a);
	int b_root = find_root(b);

	if (a_root != b_root) {
		parent[b_root] = a_root;
		set_size[a_root] += set_size[b_root];
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			int cur = str[j] - '0';
			grid[i][j] = cur;

			if (grid[i][j] == 1) continue;

			make_set(m * i + j + 1);

			if (i - 1 >= 0 && grid[i - 1][j] == 0) {
				unite(m * i + j + 1, m * (i - 1) + j + 1);
			}

			if (j - 1 >= 0 && grid[i][j - 1] == 0) {
				unite(m * i + j + 1, m * i + j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				cout << grid[i][j];
				continue;
			}
			
			memset(used_set, 0, sizeof(int) * 4);
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 1) continue;

				int root = find_root(m * nx + ny + 1);
				bool used = false;
				
				for (int l = 0; l < 4; l++) {
					if (used_set[l] == root) used = true;
				}
				if (used) continue;

				used_set[k] = root;
				grid[i][j] += set_size[root];
			}

			cout << grid[i][j] % 10;
		}
		cout << "\n";
	}
}