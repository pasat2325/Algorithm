#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<pair<int, int>> v; //시작시간,끝나는 시간 저장
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		v.push_back(make_pair(q, p));
	}

	sort(v.begin(), v.end());

	int time = v[0].first;
	int count = 1;
	for (int i = 1; i < n; i++)
	{
		if (time <= v[i].second)
		{
			count++;
			time = v[i].first;
		}
	}
	cout << count;
}