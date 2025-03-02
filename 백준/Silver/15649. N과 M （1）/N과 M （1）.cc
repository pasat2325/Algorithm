#include <iostream>
int n, m;
char ans[20];
bool chk[8];
using namespace std;

void permutation(int depth)
{
	if (depth == m)
	{
		cout << ans << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (chk[i]) continue;
		ans[depth * 2] = i + '1';
		chk[i] = true;
		permutation(depth + 1);
		chk[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < 2 * m; i++) ans[i] = ' ';
	permutation(0);
	return 0;
}