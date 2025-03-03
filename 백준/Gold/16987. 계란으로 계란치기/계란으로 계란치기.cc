#include <iostream>
#include <vector>
using namespace std;
int n, ans;
vector< pair<int, int>>eggs(10); //내구도, 무게

void bt(int e) // e == 왼손에 든 계란 번호
{
	if (e == n + 1) return;

	for (int i = 0; i < n; i++)
	{
		if (eggs[e].first <= 0) bt(e + 1);
		else if (e == i || eggs[i].first <= 0) continue;
		else
		{
			eggs[e].first -= eggs[i].second;
			eggs[i].first -= eggs[e].second;
			bt(e + 1);
			eggs[e].first += eggs[i].second;
			eggs[i].first += eggs[e].second;
		}
	}

	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (eggs[i].first <= 0) temp++;
	}
	ans = max(ans, temp);
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		eggs[i]={x,y};
	}
	bt(0);
	cout << ans;
}
