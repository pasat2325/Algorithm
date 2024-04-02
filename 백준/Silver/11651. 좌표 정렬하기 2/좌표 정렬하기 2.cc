#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int>> v;
int n;

//입력을 받고 좌표를 vector에 저장하는 함수
void input()
{	
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y; // x좌표와 y좌표 입력
		v.push_back({ x,y });
	}
}

bool sorting(pair<int, int> p1, pair <int, int> p2) {
	if(p1.second != p2.second)
		return p1.second < p2.second;
	return p1.first < p2.first;
}
void result()
{
	sort(v.begin(), v.end(), sorting);
}

int main()
{
	input();
	result();
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first <<" " << v[i].second << "\n";
	}
}