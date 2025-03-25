/*
2회 이상 멘션을 보낸 사람들의 평균 멘션 수가 준비된 메시지 수 m 보다 크다면 매크로 의심을 피할 수 없으니 -1을 출력한다.
평균 멘션 수 이하로 보낸 사람들 중 i 회 멘션을 보낸 사람의 수를 찾는다.

평균 멘션 수 이하로 멘션을 보낸 사람의 수를 P라고 할 때, i번 메시지는 i회 이상 멘션을 보낸 사람들에게 가야한다.

사람 N 명, 1 <= N <= 1e6
준비된 메시지 M개, 1 <= M <= 1e6
사람들의 멘션 횟수 P_i, 1 <= P_i <= 1e9
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> mentions(n);
	for (int i = 0; i < n; i++)
	{
		cin >> mentions[i];
	}
	// 멘션을 2회 이상한 사람들의 평균 멘션 횟수를 구한다.
	long long sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (mentions[i] >= 2) {
			cnt++;
			sum += mentions[i];
		}
	}
	long long avg = 0;
	if(cnt !=0) avg = sum / cnt;


	// 평균 멘션 횟수가 m 보다 크다면 -1을 출력하고 종료한다.
	if (avg > m) {
		cout << -1;
		return 0;
	}
	if (avg == 0) {
		cout << n; 
		for (int i = 2; i <= m; i++) {
			cout << " 0"; 
		}
		return 0;
	}

	// 그룹 A : 멘션 횟수가 avg 이하
	// 그룹 B : 멘션 횟수가 avg 초과
	int groupB = 0;
	vector<int> freq(avg + 1, 0); // 1 ~ avg번 멘션까지 멘션 횟수 (avg <= m(1e6))
	for (int i = 0; i < n; i++) {
		if (mentions[i] > avg) {
			groupB++;
		}
		else {
			freq[mentions[i]]++;
		}
	}

	vector<int> c(avg + 1, 0);
	c[avg] = freq[avg];
	for (int i = avg - 1; i >= 1; i--) {
		c[i] = c[i + 1] + freq[i];
	}

	vector<int> ans(m + 1, 0);
	ans[1] = c[1] + groupB;
	for (int i = 2; i <= avg; i++) {
		ans[i] = c[i];
	}
	for (int i = avg + 1; i <= m; i++) {
		ans[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;


}