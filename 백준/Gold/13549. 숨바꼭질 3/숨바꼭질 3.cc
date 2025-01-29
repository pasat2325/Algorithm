#include <iostream>
#include <deque>
#define R 200001
using namespace std;

int dist[R];
int n, k;

int solve()
{
	deque<int>dq;
	dq.push_back(n);
	fill(dist, dist + R, 1e9);
	dist[n] = 0;

	while (!dq.empty())
	{
		int current = dq.front();
		dq.pop_front();

		if (current == k) return dist[current];

		int next;

		next = current * 2;
		if (next < R)
			if (dist[next] > dist[current]) {
				dist[next] = dist[current];
				dq.push_front(next);
			}

		next = current - 1;
		if (next >= 0)
			if (dist[next] > dist[current] + 1)
			{
				dist[next] = dist[current] + 1;
				dq.push_back(next);
			}

		next = current + 1;
		if (next < R)
			if (dist[next] > dist[current] + 1)
			{
				dist[next] = dist[current] + 1;
				dq.push_back(next);
			}
	}

}

int main()
{
	cin >> n >> k;
	cout << solve();
}