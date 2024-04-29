#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	long long sum = 0;

	cin >> n;

	vector<char> v;

	for (int i = 0; i < n; i++)
	{
		char str;
		cin >> str;
		v.push_back(str);
		sum += (v[i] - 96) * pow(31, i);
	}

	cout << sum;

}