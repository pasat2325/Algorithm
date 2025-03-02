#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int arr[20];
int ans;
vector<int>vec;
void re(int j, int depth)
{
	if (depth == m) {
		for (int i = 0; i < m; i++) cout << vec[i] << " ";
		cout << "\n";
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
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	re(0, 0);

}
