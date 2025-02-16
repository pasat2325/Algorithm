#include <iostream>

using namespace std;

static const int inf = 1e9;
static const int cities = 101;
int dist[cities][cities];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		if (dist[s][e] != 0 || dist[s][e] != inf) dist[s][e] = (dist[s][e] < w) ? dist[s][e] : w;
		else dist[s][e] = w;
	}

	// 경유하는 점
	for (int i = 1; i <= v; i++)
	{
		//출발점
		for (int j = 1; j <= v; j++)
		{


			//도착점
			for (int k = 1; k <= v; k++)
			{

				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++) {
			if (dist[i][j] == inf)
			{
				cout << 0 << " ";
			}
            else cout << dist[i][j] << " ";
		}

		cout << "\n";
	}
}