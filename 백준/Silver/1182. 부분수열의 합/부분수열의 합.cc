#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[20];
vector<int> vec;
int ans;
void re(int j, int sum)
{
	if (sum == m && j != 0)
	{
		ans++;
	}

	if (j == n) return;
	
	for (int i = j; i < n; i++)
	{
		vec.push_back(arr[i]);
		sum += arr[i];
		re(i + 1, sum);
		sum -= arr[i];
		vec.pop_back();

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
