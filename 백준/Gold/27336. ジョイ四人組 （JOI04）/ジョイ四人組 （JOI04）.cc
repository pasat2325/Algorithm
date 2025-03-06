
#include <iostream>
#include <algorithm>
using namespace std;
int arr[4][75000];
int n;
int tallest = 0, shortest = 2e9;
bool chk_range(int a[],int low, int high)
{
	int l = 0, r = n;
	while (l < r)
	{
		int mid = (r + l) / 2;
		if (a[mid] < low)
		{
			l = mid + 1;
		}
		else r = mid;
	}
	if (l < n && a[l] <= high)
		return true;
	return false;
}

bool chk(int d) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool ok = true;
			for (int k = 0; k < 4; k++)
			{
				if (!chk_range(arr[k], arr[i][j], arr[i][j] + d))
				{
					ok = false;
					break;
				}
			}
			if (ok) return true;
		}
	}
	return false;
}


int bs(int low, int high)
{
	int ans = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (chk(mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
		{	
			int h;
			cin >> h;
			tallest = tallest > h ? tallest : h;
			shortest = shortest > h ? h : shortest;
			arr[i][j] = h;
		}
	for (int i = 0; i < 4; i++) sort(arr[i], arr[i] + n);

	cout << bs(0, tallest - shortest);

}