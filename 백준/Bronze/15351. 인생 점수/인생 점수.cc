#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin,str);
		int score = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] == ' ') continue;
			score += str[j] - 'A' + 1;
		}
		if (score == 100) cout << "PERFECT LIFE" << "\n";
		else cout << score << "\n";
	}
}