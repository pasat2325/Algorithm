#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v; //연관된 두 값을 다룰때는 pair 사용(또는 구조체)
int main()
{
	int n;
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({x,y});
	}
	sort(v.begin(), v.end()); // 첫번째 값이 같으면 자동으로 두번째 값을 기준으로 정렬해준다.
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << "\n";
	}
	return 0;
}