#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[49];
int ans[6];
vector<int> vec;
void re(int j, int depth)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; i++)	cout << vec[i] << ' ';
		cout << "\n";
		return;
	}

	for (int i = j; i < n; i++)
	{

		vec.push_back(arr[i]);
		re(i + 1, depth + 1);
		vec.pop_back();
	}
}
int main()
{
	while (true)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		re(0, 0);
		cout << "\n";

	}
}