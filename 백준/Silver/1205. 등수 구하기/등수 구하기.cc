#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int N, S, P; cin >> N >> S >> P;
	vector<int> v;

	v.push_back(S);
	for (int i = 0; i < N; i++) {
		int s; cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), comp);

	if (N == P) {
		if (v[N] == S) cout << -1;
		else {
			for (int i = 1; i <= N; i++) {
				if (v[i - 1] == S) {
					cout << i;
					return 0;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= P; i++) {
			if (v[i - 1] == S) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;

}