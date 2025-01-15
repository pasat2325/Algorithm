#include <iostream>

using namespace std;

int max_dp[3];
int min_dp[3];

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		if (i == 0)
		{
			max_dp[0] = x;
			max_dp[1] = y;
			max_dp[2] = z;

			min_dp[0] = x;
			min_dp[1] = y;
			min_dp[2] = z;

			continue;
		}
		int maxx = (max_dp[0] + x > max_dp[1] + x) ? max_dp[0] + x : max_dp[1] + x;
		int maxz = (max_dp[1] + z > max_dp[2] + z) ? max_dp[1] + z : max_dp[2] + z;
		int maxy = (max_dp[0] + y > max_dp[1] + y) ? max_dp[0] + y : max_dp[1] + y;
		maxy = (maxy > max_dp[2] + y) ? maxy : max_dp[2] + y;

		int minx = (min_dp[0] + x < min_dp[1] + x) ? min_dp[0] + x : min_dp[1] + x;
		int minz = (min_dp[1] + z < min_dp[2] + z) ? min_dp[1] + z : min_dp[2] + z;
		int miny = (min_dp[0] + y < min_dp[1] + y) ? min_dp[0] + y : min_dp[1] + y;
		miny = (miny < min_dp[2] + y) ? miny : min_dp[2] + y;

		max_dp[0] = maxx;
		max_dp[1] = maxy;
		max_dp[2] = maxz;

		min_dp[0] = minx;
		min_dp[1] = miny;
		min_dp[2] = minz;
	}
	int max = (max_dp[0] > max_dp[1]) ? max_dp[0] : max_dp[1];
	max = (max > max_dp[2]) ? max : max_dp[2];

	int min = (min_dp[0] < min_dp[1]) ? min_dp[0]: min_dp[1];
	min = (min < min_dp[2]) ? min : min_dp[2];

	cout << max << " " << min;
}