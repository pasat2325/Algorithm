#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int max_budget;

bool isPossible(int value)
{
	int total_budget = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] <= value) total_budget += vec[i];
		else total_budget += value;
	}
	bool res = total_budget <= max_budget ? true : false;
	return res;
}

int bi_search(int low, int high)
{
	int result = low;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (isPossible(mid))
		{
			result = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	cin >> max_budget;

	cout << bi_search(0, vec[n - 1]);
}