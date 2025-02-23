// 그리디
// 오름차정렬 후 차이를 더함. 마지막에 가장 큰수와 작은 수를 연결한다.

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int beads[1000];
	for (int i = 0; i < n; i++)
	{
		int bead;
		cin >> bead;
		beads[i] = bead;
	}

	sort(beads, beads + n);

	int result = 0;
	for (int i = 1; i < n; i++)
	{
		result += beads[i] - beads[i - 1];
	}
	cout << result + beads[n - 1] - beads[0];
}