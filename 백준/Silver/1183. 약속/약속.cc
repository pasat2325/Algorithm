#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> ai(n);
	vector<long long> bi(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> ai[i] >> bi[i];
	}

	vector<long long> ci(n);

	for (int i = 0; i < n; i++)
	{
		ci[i] = bi[i] - ai[i];
	}

	sort(ci.begin(), ci.end());

	if (n & 1)
		cout << 1 << "\n";
	else
		cout << ci[n / 2] - ci[n / 2 - 1] + 1 << "\n";

	return 0;
}