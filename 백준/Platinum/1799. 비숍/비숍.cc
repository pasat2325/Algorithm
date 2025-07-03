#include <iostream>
#include <vector>
using namespace std;

int n; //n x n 


int slash = 0, backslash = 0;
int answer = 0;

void solve(int idx, int cnt, vector<pair<int, int>>& cells) {
	if (idx == cells.size()) {
		answer = max(answer, cnt);
		return;
	}
	int x = cells[idx].first;
	int y = cells[idx].second;

	int s = x + y;
	int b = x - y + n - 1;

	if (!(slash & (1 << s)) && !(backslash & (1 << b))) {
		slash |= (1<<s);
		backslash |= (1 << b);
		solve(idx + 1, cnt + 1, cells);
		slash ^= (1 << s);
		backslash ^= (1 << b);
	}
	solve(idx + 1, cnt, cells);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int, int>> white, black;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				if ((i + j) % 2 == 0) white.push_back({ i,j });
				else black.push_back({ i,j });
			}
		}
	}

	answer = 0;
	solve(0,0,white);
	int w = answer;

	answer = 0;
	slash = backslash = 0;
	solve(0, 0, black);
	int b = answer;
	cout << w + b;


}