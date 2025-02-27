#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool comp(string a, string b)
{
	return a + b > b + a;
}
int main()
{
	int n;
	cin >> n;
	vector<string>vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), comp);
	string answer = "";
	for (int i = 0; i < n; i++)
	{
		answer += vec[i];
	}
	if (answer[0] == '0') cout << 0;
	else cout << answer;
}