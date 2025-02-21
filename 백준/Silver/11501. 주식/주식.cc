/*
dailyStock[]에 역순으로 접근한다.
1. dailyStock[i] >= maxStock value 이면, 해당 날짜에 stock을 샀을 때 더 높은 가격에 팔 기회가 없다.
 즉 이득을 볼 수 없으므로 사지 않고 maxStock value를 dailyStock[i]로 갱신한다.

2. dailyStock[i] < maxStock 이면, 해당 날짜에 stock을 샀을 때 maxStock value 에 이득을 보며 팔 수 있다.
그러므로 주식을 사서 profit에 더해준다.

3. profit의 최대값: N = 1,000,000 이고 maxStock value = 10,000, 나머지 dailyStock[i] = 1이면
 대략 10,000 * 1,000,000 = 백억이므로 long long 타입으로 선언한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc, days;
	int maxStock;
	long long profit;

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		cin >> days;
		vector<int> dailyStock(days);
		maxStock = 0;
		profit = 0;
		for (int j = 0; j < days; j++)
		{
			int stockVal;
			cin >> stockVal;
			dailyStock[j] = stockVal;
		}

		for (int j = days - 1; j >= 0; j--)
		{
			if (dailyStock[j] >= maxStock) {
				maxStock = dailyStock[j];
			}

			else {
				profit += maxStock - dailyStock[j];
			}
		}
		cout << profit << "\n";
	}
	return 0;
}