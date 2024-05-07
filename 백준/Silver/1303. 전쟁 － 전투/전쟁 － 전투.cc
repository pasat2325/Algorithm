#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited_white[101][101];
bool visited_blue[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int power = 1;

int dfs(vector<vector<int>>& v, int x, int y)
{

	if (v[x][y] == 0) { // blue
		visited_blue[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && !visited_blue[next_x][next_y] && v[next_x][next_y] == 0) {
				dfs(v, next_x, next_y);
				power++;
			}
		}
	}
	else { 
		visited_white[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && !visited_white[next_x][next_y] && v[next_x][next_y] == 1) {
				dfs(v, next_x, next_y);
				power++;
			}
		}
	}
	return power;
}


int main()
{
	cin >> n >> m;
	vector<vector<int>> graph(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		string colorstr;
		cin >> colorstr;
		for (int j = 0; j < n; j++)
		{
			char colorchar = colorstr[j];
			if (colorchar == 'W') { //색이 blue 면 0 , white면 1대입
				graph[i][j] = 1;
			}
		}
	}

	int blue_power = 0;
	int white_power = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			power = 1;
			if (graph[i][j] == 0 && !visited_blue[i][j]) {
				
				int num = dfs(graph, i, j);
				blue_power += num * num;
			}
			else if (graph[i][j] == 1 && !visited_white[i][j]) {
				int num = dfs(graph, i, j);
				white_power += num * num;
			}
		}
	}
	cout << white_power << " " << blue_power;
}