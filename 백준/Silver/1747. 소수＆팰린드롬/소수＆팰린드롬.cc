#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
const int max_num = 2000000;
int main()
{
	int n;
	cin >> n;
	vector<int>primes(max_num + 1, 1);
	primes[1] = false;
	for (int i = 2; i < sqrt(max_num) + 1; i++)
	{
		if (primes[i] == true) {
			int j = 2;
			while (i * j <= max_num)
			{
				primes[i * j] = false;
				j++;
			}
		}
	}

	for (int i = 1; i < max_num + 1; i++)
	{
		int temp = i;
		string strnum1;
		if (i >= n && primes[i] == true)
		{
			while (temp > 0)
			{
				strnum1.push_back(temp%10 + '0');
				temp /= 10;
			}
			string strnum2 = strnum1;
			reverse(strnum2.begin(), strnum2.end());
			if (strnum1 == strnum2)
			{
				cout << i;
				break;
			}
		}
	}
}