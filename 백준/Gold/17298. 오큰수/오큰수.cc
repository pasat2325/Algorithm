#include <iostream>
#include <stack>
#define MAX_N 1'000'001
using namespace std;

int ocn[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	stack<pair<int,int>> s;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		while (!s.empty() && s.top().first < x) {
			ocn[s.top().second] = x;
			s.pop();
		}

		s.push({ x, i });
	}
	for (int i = 1; i <= n; i++) {
		if (ocn[i] == 0) cout << -1 << " ";
		else cout << ocn[i] << " ";
	}
}