#include <iostream>

using namespace std;

int dp[1000];
int arr[1000];


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr[i] = x;
	}
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
	}

	int dpmax = 1;
	for (int i = 1; i < n; i++)
	{
		int localmax = 0;
		for (int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])	localmax = localmax < dp[j] ? dp[j] : localmax;

		}
		dp[i] = localmax + 1;

		dpmax = dp[i] > dpmax ? dp[i] : dpmax;
	}
	
	cout << dpmax;
}