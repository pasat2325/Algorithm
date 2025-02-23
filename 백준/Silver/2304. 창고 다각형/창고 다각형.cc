#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[1001];
	memset(arr, 0, sizeof(arr));
	int max_h = 0 , max_pos = 0;

	for (int i = 0; i < n; i++)
	{
		int l, h;
		cin >> l >> h;
		if (max_h < h)
		{
			max_h = h;
			max_pos = l;
		}
		arr[l] = h;
	}

	int result = max_h;
	int localMax = 0;
	for (int i = 1; i < max_pos; i++)
	{
		localMax = max(arr[i], localMax);
		result += localMax;
	}

	localMax = 0;
	for (int i = 1000; i > max_pos; i--)
	{
		localMax = max(arr[i], localMax);
		result += localMax;
	}

	cout << result;
}