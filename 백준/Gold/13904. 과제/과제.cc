#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N; cin >> N;
	priority_queue<pair<int, int>> pq;
	int md = -1;
	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;

		pq.push({ w,d });
		md = max(d, md);
	}

	vector<bool>visited(md + 1,false);

	int sum = 0;
	while (!pq.empty()) {
		int d = pq.top().second;
		int w = pq.top().first;
		pq.pop();
		int temp = d;
		while (temp > 0 && visited[temp]) {
			temp--;
		}
		if (temp == 0) continue;
		visited[temp] = true;
		sum += w;
	}
	cout << sum;
}