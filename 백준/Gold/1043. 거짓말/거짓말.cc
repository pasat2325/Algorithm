#include <iostream>
#include <vector>
using namespace std;

int n, m, k; // 사람의 수, 파티의 수, 진실을 아는 사람의 수
int parent[51];
vector<int> knowing;
vector<vector<int>> v(50);

int getParent(int num)
{
	if (parent[num] == num) return num;
	return getParent(parent[num]);
}
void unionSet(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a != b) parent[a] = b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;

	//진실을 아는 사람을 knowing 벡터에 추가
	while (k--)
	{
		int t;
		cin >> t;
		knowing.push_back(t);
	}

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int p; // 파티 참가 사람의 수
		cin >> p;
		int num;
		int prev;

		for (int j = 0; j < p; j++)
		{
			// 파티 참가자의 수가 1보다 크다면 그룹을 지어준다.
			if (j >= 1)
			{
				prev = num;
				cin >> num;
				unionSet(prev, num);
			}
			else cin >> num;

			v[i].push_back(num);
		}
	}
	for (auto& list : v)
	{
		bool flag = false;
		for (auto i : list)
		{
			if (flag) break;
			for (auto k : knowing)
			{
				if (getParent(i) == getParent(k))
				{
					flag = true;
					break;
				}
			}
		}
		if (flag) m--;
	}
	cout << m;
}