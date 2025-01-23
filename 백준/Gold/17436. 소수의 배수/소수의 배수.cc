#include <iostream>

using namespace std;

int main()
{
	int n;
	long long m;
	cin >> n >> m;

	int prime[10] = {0,};

	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		prime[i] = p;
	}

	long long result = 0;

	for (int i = 1; i < (1 << n); i++)
	{

		long long re = 1;
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				re *= prime[j];
				count++;
			}
		} 
		
		
		if (count % 2 != 0) result += m/re;
		else result -= m/re;
	}
	cout << result;

}