#include <iostream>

using namespace std;

int main()
{
	int N = 0, M = 0, p = 0, q = 0;
	int set = 1000, single = 1000;
	cin >> N >> M;
	
	while (M--)
	{
		cin >> p >> q;
		set = min(set, p);
		single = min(single, q);
	}
	cout << min((N / 6 + 1) * set, min(N / 6 * set + N % 6 * single, N * single)) << '\n';
}