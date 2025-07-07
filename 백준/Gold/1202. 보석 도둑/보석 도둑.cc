#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int,int>> jewels;
	for (int i = 0; i < n; i++) {
		int weight, value;
		cin >> weight >> value;
		jewels.push_back({ weight,value });
	}
	sort(jewels.begin(), jewels.end());

	vector<int> b;
	for (int i = 0; i < k; i++) {
		int b_weight;
		cin >> b_weight;
		b.push_back(b_weight);
	}
	sort(b.begin(), b.end());

	priority_queue<int> pq;

	long long ans = 0;
	int index = 0;
	for (int i = 0; i < k; i++) {
		int cur_bag_weight = b[i];
		for (int j = index; j < n; j++) {
			if (jewels[j].first > cur_bag_weight) {
				index = j;
				break;
			}
			pq.push(jewels[j].second);
			index++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}