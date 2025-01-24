#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct edge {
	int spoint;
	int epoint;
	int dis;
};

bool compare1(edge a, edge b) {

	return a.dis < b.dis;
}

vector<int>parent(1001);
vector<edge>ev;

int getParent(int num)
{
	if (parent[num] == num) return num;
	return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	if (a != b) parent[a] = b;
}

bool findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return (a == b);
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int s, e, d;
		cin >> s >> e >> d;
		edge ed = { s,e,d };
		ev.push_back(ed);
	}

	sort(ev.begin(), ev.end(), compare1); //간선기준 오름차순 정렬

	int result = 0;

	for (int i = 0; i < m; i++)
	{
		if (!findParent(ev[i].spoint, ev[i].epoint)){
			result += ev[i].dis;
			unionParent(ev[i].spoint, ev[i].epoint); 
		}
	}
	cout << result;
}