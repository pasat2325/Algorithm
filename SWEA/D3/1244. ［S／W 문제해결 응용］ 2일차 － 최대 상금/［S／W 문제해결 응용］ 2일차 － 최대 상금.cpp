#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;
const int max_n = 1'000'000;
int ans = 0;
bool visited[max_n];
bool f = false;

int to_int(string str) {
	int x = 1;
	int temp = 0;
	for (int i = str.length() - 1; i >= 0; i--) {
		temp += (str[i] - '0') * x;
		x *= 10;
	}
	return temp;
}

bool check(string str) {
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			if (i == j) continue;
			if (str[i] == str[j]) return true;
		}
	}
	return false;
}

void solve(int depth, int target, string str) {
	if (depth == target) {
		int temp = to_int(str);
		ans = max(ans, temp);
		return;
	}

	int num = to_int(str);
	visited[num] = true;
	if (depth - target % 2 == 0 || f) {
		ans = max(ans, num);
	}

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length(); j++) {
			if (i == j) continue;
			string nx = str;
			char tc = nx[j];
			nx[j] = nx[i];
			nx[i] = tc;
			
			int num2 = to_int(nx);
			if (visited[num2]) continue;

			solve(depth + 1, target, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		string str; cin >> str;
		int k; cin >> k;
		ans = 0;
		memset(visited, 0, sizeof(bool) * max_n);
		f = check(str);
		solve(0, k, str);
		cout << "#" << i << " " << ans << "\n";
	}
}