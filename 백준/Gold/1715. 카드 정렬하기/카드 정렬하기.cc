#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(-x);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		ans += a + b;
		pq.push(-(a + b));
	}
	//if (ans == 0) ans = -pq.top();

	cout << ans;

}
