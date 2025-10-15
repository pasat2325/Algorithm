#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n * n; i++) {
		int x; cin >> x;
		if (i < n) {
			pq.push(x);
		}
		else {
			if (pq.top() < x) {
				pq.pop();
				pq.push(x);
			}
		}
	}
	cout << pq.top();

}