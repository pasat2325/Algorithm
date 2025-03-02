#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[20];
int ans;
void re(int j, int sum)
{
	if (j == n)
	{
		if (sum == m) ans++;
		return;
	}

	
	re(j + 1, sum);
	re(j + 1, sum + arr[j]);
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
	if (m == 0) cout << --ans;
	else
		cout << ans;
}
