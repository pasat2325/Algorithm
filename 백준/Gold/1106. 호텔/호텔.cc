#include <iostream>
#include <algorithm>
#define MAX_V 200000
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
	int aa = a.first;
	int bb = b.first;
	return a.first > b.first;
}
int dp[MAX_V];
int main()
{
	int c, n; // 목표 고객 수 c, 홍보 도시 수 n
	cin >> c >> n;
	pair<int,int> carr[21];
	for (int i = 0; i < n; i++) {
		int cost, cust;
		cin >> cost >> cust;
		carr[i] = { cost,cust };
	}
	sort(carr, carr + n, comp);

	for (int i = 1; i <= MAX_V; i++) {

		for (int j = 0; j < n; j++) {
			
			int temp;
			if (i - carr[j].first < 0) {

				dp[i] = dp[i - 1];
				continue;
			}
			temp = dp[i - carr[j].first] + carr[j].second;
			dp[i] = temp > dp[i] ? temp : dp[i];

		}
	}
	for (int i = 0; i < MAX_V; i++) {
		if (dp[i] >= c) {
			cout << i;
			break;
		}
	}
}