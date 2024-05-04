#include <iostream>

using namespace std;

int main()
{

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int *arr= new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	
	for (int i = 1; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i];
	}



	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		
		if (s == 1)
			cout << arr[e - 1] << "\n";
		else
			cout << arr[e - 1] - arr[s - 2] << "\n";
	}
}