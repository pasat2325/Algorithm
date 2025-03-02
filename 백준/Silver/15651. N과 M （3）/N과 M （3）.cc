#include <iostream>
int n, m;
char ans[17];

using namespace std;

void permutation(int j, int depth)
{
	if (depth == m)
	{
		cout << ans << "\n";
		return;
	}
	for (int i = j; i < n; i++)
	{

		ans[depth * 2] = i + '1';

		permutation(0, depth + 1);

	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 2 * m; i++) ans[i] = ' ';
	permutation(0,0);
	return 0;
}