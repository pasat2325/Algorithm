#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int binary_search(vector<int>&v, int num)
{
	int low = 0;
	int high = v.size() - 1;
	int idx = -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (v[mid] == num) {
			idx = mid;
			break;
		}
		else if (num < v[mid]) high = mid - 1;
		else if (num > v[mid]) low = mid + 1;
	}
	return idx;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v1(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}

	set <int> s(v1.begin(), v1.end());
	vector<int> v2(s.begin(), s.end());

	for (int i = 0; i < n; i++)
	{
		cout << binary_search(v2, v1[i]) << " ";
	}
}
