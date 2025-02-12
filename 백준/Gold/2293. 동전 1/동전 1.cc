/*
	1 2 3 4 5 6 7 8 9 10
1	1 1 1 1 1 1 1 1 1 1
2	0 1 
5
dp  
i -> 현재 고려중인 동전의 가치
j -> 현재 만들려고 하는 가치

동전 i가 j의 가치를 넘는다면 dp[j] = dp[j]
동전 i가 j의 가치보다 똑같거나, 작다면 dp[j] = dp[j] + dp[j - i]

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	
	vector<int>coin;
	int dp[10001];
	dp[0] = 1;
	for (int i = 1; i <= k; i++)
	{
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		coin.push_back(c);
	}
	sort(coin.begin(), coin.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (coin[i] <= j)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
	}
	cout << dp[k];
}