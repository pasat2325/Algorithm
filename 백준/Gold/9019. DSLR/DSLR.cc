#include <queue>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct seq {
	int parent;
	char cmd;
};

struct seq seqarr[10000];
bool visit[10000] = { false, };
int nxcode;

void solve(int origin, int target)
{
	queue<int>q;
	q.push(origin);
	visit[origin] = true;
	while (!q.empty())
	{
		int code = q.front();
		q.pop();
		//D
		nxcode = 2 * code % 10000;
		if (!visit[nxcode])
		{
			struct seq dstruct = { code, 'D' };
			seqarr[nxcode] = dstruct;
			if (nxcode == target)break;
			q.push(nxcode);
			visit[nxcode] = true;
		}

		//S
		nxcode = (code - 1 < 0) ? 9999 : code - 1;
		if (!visit[nxcode])
		{
			struct seq sstruct = { code, 'S' };
			seqarr[nxcode] = sstruct;
			if (nxcode == target) break;
			q.push(nxcode);
			visit[nxcode] = true;
		}

		//L
		nxcode = code % 1000 * 10 + code/1000;
		if (!visit[nxcode])
		{
			struct seq lstruct = { code, 'L' };
			seqarr[nxcode] = lstruct;
			if (nxcode == target)break;
			q.push(nxcode);
			visit[nxcode] = true;
		}

		//R
		nxcode = code % 10 * 1000 + code/10;

		if (!visit[nxcode])
		{
			struct seq rstruct = { code, 'R' };
			seqarr[nxcode] = rstruct;
			if (nxcode == target)break;
			q.push(nxcode);
			visit[nxcode] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, origin, target;
	cin >> t;
	

	for (int i = 0; i < t; i++)
	{
		cin >> origin >> target;

		memset(visit, false, sizeof(visit));
		memset(seqarr, 0, sizeof(seqarr));
		seqarr[origin].parent = origin;

		solve(origin, target);
		vector<char>result;
		while (nxcode != origin)
		{
			result.push_back(seqarr[nxcode].cmd);
			nxcode = seqarr[nxcode].parent;
		}

		for (int i = result.size() - 1; i >= 0; i--)
		{
			cout << result[i];
		}
		cout << "\n";
	}
}