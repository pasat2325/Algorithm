#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string text;
	cin >> text;

	if (n == 1) cout << text;

	else {
		vector<int>v(text.size(), 0);

		for (int i = 1; i < n; i++)
		{
			string next;
			cin >> next;

			for (int j = 0; j < text.size(); j++)
			{

				if (!(text[j] == next[j]))
				{
					v[j] = 1;
				}
			}
		}

		for (int i = 0; i < text.size(); i++)
		{
			if (v[i] == 0) cout << text[i];
			else cout << "?";
		}
	}
	
}