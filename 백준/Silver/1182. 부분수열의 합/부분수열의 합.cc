#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[20];
int ans;
void re(int j, int sum)
{
	if (sum == m && j != 0) ans++;

	
	for (int i = j; i < n; i++)
	{

		sum += arr[i];
		re(i + 1, sum);
		sum -= arr[i];

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	re(0, 0);
	cout << ans;
}
