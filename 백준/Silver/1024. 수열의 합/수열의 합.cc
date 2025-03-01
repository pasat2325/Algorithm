#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;

	for (int i = l; i <= 100; i++)
	{
		int d = n / i;
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += d;
			d++;
		}

		if (sum == n)
		{
			vector<int>v;
			for (int j = 0; j < i; j++)
			{
				v.push_back(--d);
			}
			for (int k = i - 1; k >= 0; k--)
			{
				cout << v[k] << " ";
			}
			return 0;
		}
		else {
			int cnt = 0;

			while (sum > n)
			{
				sum -= i;
				cnt++;
				if (sum == n)
				{
					d = d - cnt;
					vector<int>v;
					for (int j = 0; j < i; j++)
					{
						v.push_back(--d);
						if (d < 0)
						{
							cout << -1;
							return 0;
						}

					}
					for (int k = i - 1; k >= 0; k--)
					{
						cout << v[k] << " ";
					}
					return 0;
				}

			}
		}
	}
	cout << -1;
	return 0;

}
