#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int& a : A)
		cin >> a;

	int M;
	cin >> M;
	vector<tuple<int, int, int>> LRC(M);
	for (auto& [l, r, c] : LRC)
		cin >> l >> r >> c, l--, r--;

	set<vector<int>> vis;
	using T = pair<int, vector<int>>;
	priority_queue<T, vector<T>, greater<T>> Q;
	Q.emplace(0, A);
	while (!Q.empty())
	{
		auto [d, v] = Q.top();
		Q.pop();
		if (vis.count(v))
			continue;
		vis.insert(v);
		if (is_sorted(v.begin(), v.end()))
		{
			cout << d << "\n";
			return 0;
		}
		for (auto [l, r, c] : LRC)
		{
			auto T = v;
			swap(T[l], T[r]);
			Q.emplace(d + c, T);
		}
	}
	cout << -1 << "\n";
	return 0;
}