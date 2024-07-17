#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int te;
	cin >> te;
	unordered_map<string, int> ::iterator iter;
	int answer;

	for (int i = 0; i < te; i++)
	{
		unordered_map<string, int> u;
		int n;
		cin >> n;
		answer = 1;

		for (int j = 0; j < n; j++)
		{
			string name, type;
			cin >> name >> type;
			if (u.find(type) != u.end())
			{
				u[type]++;
			}
			else u[type] = 1;
		}

		for (iter = u.begin(); iter != u.end(); iter++)
		{
			answer *= (iter->second) + 1;
		}
		cout << answer - 1 << endl;
	}
}