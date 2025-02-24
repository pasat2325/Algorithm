#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int x, y;
		cin >> x >> y;
		int distance = y - x;
		double distanceSqrt = sqrt(distance);
		int distanceSqrtR = round(distanceSqrt);
		if (distanceSqrt <= distanceSqrtR) cout << 2 * distanceSqrtR - 1 << "\n";
		else cout << 2 * distanceSqrtR << "\n";
	}
}