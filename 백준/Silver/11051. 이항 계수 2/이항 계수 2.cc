#include <iostream>

using namespace std;

int dp[1001][1001];
int comb(int n, int k)
{
	if (dp[n][k] != 0)
		return dp[n][k];
	else if (k == 0 || k == n)
		return 1;

	return dp[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k)) % 10007;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << comb(n,k);

}