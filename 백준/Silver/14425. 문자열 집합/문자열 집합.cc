#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<string, bool>map;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		map.insert({ str, true });
	}
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;
		if (map[str]) cnt++;
	}
	cout << cnt;
}