#include <iostream>
#include <vector>
using namespace std;

const int MAX_P = 2'000'003; // 200만 이상의 수 중 가장 작은 소수
vector<bool> check(MAX_P + 1);
vector<bool> exist(MAX_P + 1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		exist[x] = true;
	}

	if (!exist[0]) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i <=MAX_P; i++) {
		if (i == 0 || !exist[i]) continue;
		for (int j = 0; j <= MAX_P / i; j++) {
			if (!exist[j]) continue;
			check[i * j] = true;
		}
	}
	
	for (int i = 1; i <= MAX_P; i++) {
		if (!check[i]) {
			cout << i << "\n";
			return 0;
		}
	}


}
