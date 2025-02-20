#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>vec;
	long long unhappy = 0;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		unhappy += abs(vec[i] - (i + 1));
	}
	cout << unhappy;
}