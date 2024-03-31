#include <iostream>

using namespace std;

// 0의 개수는 5가 곱해진 수다.
// 5! => 1, 25! => 6개

int cnt = 0;

int solve(int n)
{
	if (n < 5) return cnt;

	cnt += n / 5;

	if ((n / 5) % 5 == 0 || (n / 5) > 5) {
		solve(n / 5);
	}
	
	return cnt;
}

int main()
{
	int N;
	cin >> N;

	solve(N);
	cout << cnt;
	
}

