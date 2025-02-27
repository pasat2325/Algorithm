#include <iostream>
#include <vector>
using namespace std;

int arr[200000];
long long dp[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, q, pointer;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (i == 0) dp[i] = i;
		else dp[i] = dp[i - 1] + arr[i - 1];
	}
	dp[n] = dp[n - 1] + arr[n - 1];

	pointer = 0;
	for (int i = 0; i < q; i++)
	{
		int query;
		cin >> query;
		if (query == 3)
		{
			int a,b,startp,endp;
			cin >> a >> b;
			startp = (pointer + a - 1) % n;
			endp = (pointer + b - 1) % n;

			if (startp == endp) cout << arr[startp] << "\n";
			else if (startp < endp) cout << dp[endp + 1] - dp[startp] << "\n";
			else cout << dp[n] - dp[startp] + dp[endp + 1] << "\n";
		}
		else
		{
			int k;
			cin >> k;
			if (query == 1) pointer = (n - k + pointer) % n;
			else pointer = (k + pointer) % n;
		}
	}
}