#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	while (n < m)
	{
		if (m % 10 == 1) m = m / 10;
		else if (m % 2 == 0) m = m / 2;
		else{
			cout << -1;
			return 0;
		}

		cnt++;
	}

	if (n > m) cout << -1;
	else cout << cnt + 1;
	return 0;
}