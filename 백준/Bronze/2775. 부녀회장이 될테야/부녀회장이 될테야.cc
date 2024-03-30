#include <iostream>

using namespace std;

//DP
int main()
{
	int apart[15][15];
	for (int i = 0; i < 15; i++)
	{
		apart[0][i] = i;
	}
	for (int i = 0; i < 15; i++)
	{
		apart[i][0] = 0;
	}
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			apart[i][j] = apart[i - 1][j] + apart[i][j - 1];
		}
	}
	int T, k, n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;
		cout << apart[k][n] << "\n";
	}
	
}