#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int houses[200000];

bool checkRouter(int minDis)
{
	int prev = houses[0];
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (houses[i] - prev >= minDis)
		{
			cnt++;
			prev = houses[i];
			
		}
		if (cnt >= m) return true;
	}
	return false;
}

int bs(int low, int high)
{
	int result = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (checkRouter(mid))
		{
			result = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		houses[i] = d;
	}
	sort(houses, houses + n);
	int result = bs(1, houses[n - 1] - houses[0]);
	cout << result;
}