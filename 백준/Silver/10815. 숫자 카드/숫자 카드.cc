#include <iostream>
#include <algorithm>
using namespace std;

bool bs(int a[], int n, int target)
{
	int low = 0;
	int high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (target == a[mid]) return true;
		else if (target < a[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return false;
}


int a[500000];
int b[500000];

int main()
{
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i] = x;
	}

	cin >> m;
	for (int i = 0; i <m; i++)
	{
		int x;
		cin >> x;
		b[i] = x;
	}

	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		cout << bs(a, n, b[i]) <<" ";
	}
}