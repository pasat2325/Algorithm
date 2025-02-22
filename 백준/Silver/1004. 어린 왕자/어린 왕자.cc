#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct stellar {
	int x;
	int y;
	int radius;
};

bool compare(stellar a, stellar b)
{
	return a.radius < b.radius;
}

bool isIn(int radius, int stellx, int stelly, int x, int y)
{
	return ((abs(stellx - x) * abs(stellx - x) + abs(stelly - y) * abs(stelly - y)) < radius * radius);
}

int main()
{
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int stellarNum;
		cin >> stellarNum;
		vector<struct stellar>stellars;
		for (int i = 0; i < stellarNum; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			stellars.push_back({ x,y,r });
		}

		//radius 오름차순 정렬
		sort(stellars.begin(), stellars.end(), compare);


		int sp_cnt = 0;
		int ep_cnt = 0;

		for (int i = 0; i < stellarNum; i++)
		{

			bool sp_isIn = isIn(stellars[i].radius, stellars[i].x, stellars[i].y, sx, sy);
			bool ep_isIn = isIn(stellars[i].radius, stellars[i].x, stellars[i].y, ex, ey);

			if (sp_isIn && ep_isIn) break;
			else if (sp_isIn) sp_cnt += 1;
			else if (ep_isIn) ep_cnt += 1;
		}

		cout << sp_cnt + ep_cnt << "\n";
	}
}