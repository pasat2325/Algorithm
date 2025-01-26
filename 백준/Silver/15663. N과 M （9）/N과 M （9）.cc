#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int in[8];
int out[8];
bool visit[8];

void solve(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << out[i] << " ";
		cout << "\n";
		return;
	}
	
	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && in[i] != prev)
		{
			out[cnt] = in[i];
			visit[i] = true;
			prev = out[cnt];
			solve(cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		in[i] = x;
	}

	sort(in, in + n);

	solve(0);
}