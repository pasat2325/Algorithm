#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;


	int arr[200000];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int num = arr[0];
	long long result = 1;
	long long count = 1;


	for (int i = 1; i < n; i++)
	{
		if (num < arr[i])
		{
			num = arr[i];
			count++;
			result += count;

		}
		else
		{
			count = 1;
			num = arr[i];
			result++;
		}
	}
	cout << result;
}