#include <iostream>
#include <climits>
using namespace std;
int n, m;
int map[52][52];
int dp[52][52];
bool visited[52][52];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool hasCycle = false;

int dfs(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m || map[x][y] == 0) return 0;
	if (visited[x][y]) {
		hasCycle = true;
		return 0;
	}
	if (dp[x][y]) return dp[x][y];

	visited[x][y] = true;
	int dist = map[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * dist;
		int ny = y + dy[i] * dist; 
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;
	return dp[x][y];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			if (str[j - 1] == 'H') map[i][j] = 0;
			else map[i][j] = str[j - 1] - '0';
		}
	}
	
	int result = dfs(1, 1);
	if (hasCycle) cout << -1;
	else cout << result;
}