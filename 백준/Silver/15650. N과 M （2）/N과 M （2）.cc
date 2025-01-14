#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;

void comb(int n, int m, int start)
{
	if (vec.size() == m)
	{
		for (int i : vec) {
			cout << i << " ";
		}
		cout << endl;
		return;
	}
	for (int i = start; i <= n; i++)
	{
		vec.push_back(i);
		comb(n, m, i + 1);
		vec.pop_back();
	}
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	comb(n, m, 1);
}