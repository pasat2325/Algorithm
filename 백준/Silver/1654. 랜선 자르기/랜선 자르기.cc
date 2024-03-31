#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//이분탐색,매개변수탐색
int k, n; // 랜선의 개수, 만들어야하는 랜선의 개수
vector<int> lan;

void input()
{
	cin >> k >> n;
	lan.assign(k, 0);

	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}
}

bool isPossible(int len) {
	int cnt = 0;

	for (int i = 0; i < k; i++)
	{
		cnt += lan[i] / len;
	}
	if (cnt >= n) return true;
	else  return false;
}

void solve() {
	sort(lan.begin(), lan.end());

	unsigned int left = 1, right = lan[lan.size() - 1];
	unsigned int result = 0;

	while (left <= right) {
		unsigned int mid = (left + right) / 2;

		if (isPossible(mid)) {
			result = max(result, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	return 0;
}