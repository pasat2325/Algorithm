#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cr(string str, int i, int j)
{
	string p1, p2, p3;
	p1 = str.substr(0, i + 1);
	p2 = str.substr(i + 1, j - i);
	p3 = str.substr(j + 1);
	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());
	reverse(p3.begin(), p3.end());
	return p1 + p2 + p3;
}


int main()
{
	string str;
	cin >> str;
	string result(50, 'z');
	for (int i = 0; i <= str.length() - 3; i++)
	{
		for (int j = i + 1; j <= str.length() - 2; j++)
		{
			result = min(cr(str, i, j), result);
		}
	}
	cout << result;
}