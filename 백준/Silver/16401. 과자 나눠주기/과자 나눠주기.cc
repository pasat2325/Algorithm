/*
1. 조카의 수 m과 과자의 수 n을 입력받고.. n번만큼 과자의 길이를 입력받는다.
2. 과자의 수가 매우 많으니 이분 탐색을 위해 과자의 길이를 정렬한다.
3. 조카들은 모두 서로 같은 길이의 과자를 받아야 한다. 즉, cut을 했을 때, snack[i] / cut 을 더한 값이 m이상이어야한다.
4. 즉 low <= high일때까지 반복하되
4-1. snack[i] / cut 를 더한 cnt 변수가 m 이상인 경우 max = cut, low = cut + 1;
4-2. snack[i] / cut 를 더한 cnt 변수가 m 미만인 경우 high = cut - 1;

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void binary_search(vector<int>&v, int target)
{
	int low = 0;
	int high = v.back();
	int max = 0;
	while (low <= high)
	{
		int cut = (low + high) / 2;
		int cnt = 0;

		for (int i = 0; i < v.size(); i++) {
			if (cut > 0)
				cnt += v[i] / cut;
			else cnt += v[i];
		}


		if (cnt >= target)
		{
			max = cut;
			low = cut + 1;
		}
		else high = cut - 1;
	}

	if (max == 0) cout << 0;
	else cout << max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<int>v;

	for (int i = 0; i < n; i++)
	{
		int snackh;
		cin >> snackh;
		v.push_back(snackh);
	}
	sort(v.begin(), v.end());
	binary_search(v, m);
}