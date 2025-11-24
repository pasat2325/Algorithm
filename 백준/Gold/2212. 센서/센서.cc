#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	vector<int> dist(N - 1);
	for (int i = 0; i < N - 1; i++) {
		dist[i] = v[i + 1] - v[i];
	}
	sort(dist.begin(), dist.end());

	int res = 0;
	int limit = N - K;
	for (int i = 0; i < limit; i++) {
		res += dist[i];
	}
	cout << res;

}