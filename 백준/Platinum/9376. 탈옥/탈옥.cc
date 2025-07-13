/*
죄수1, 죄수2, 상근이가 동시에 만나는 좌표에서 탈출이 가능하다.

죄수1, 죄수2, 상근이 3명의 좌표에서부터 다익스트라를 모두 수행한 뒤 각 지점마다 수행 값을 더해준다.


조건1. 만약 죄수1, 죄수2, 상근이가 문(#)에서 만나면 -2를 해줘야 한다.
조건2. 죄수1, 죄수2, 상근이가 길(.)에서 만나면 -2를 하지 않는다.

특정 2명 이상이 서로 중복된 문을 열었고, 길에서 3명이 만나는 경우는 문을 연 최소 횟수 정답을 보장하지 않는 유일한 경우다.

위의 경우를 제외하면 모든 경우에서 조건1과 조건2를 통해 정답 후보가 된다. (위의 특수 경우에서도, 중복된 문에서 3명이 만나는 경우가 문을 연
최소 횟수 정답이 될 수 있는 후보이므로 어차피 정답은 항상 도출된다.)
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 1e8
using namespace std;
int n, m;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[102][102];
pair<int, int> psnr1, psnr2;

vector<vector<int>> dijk(int sx, int sy) {
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> dist(102, vector<int>(102, INF));
	pq.push({ 0, {sx,sy} });
	dist[sx][sy] = 0;

	while (!pq.empty()) {
		int curr_x = pq.top().second.first;
		int curr_y = pq.top().second.second;
		int curr_dist = -pq.top().first;
		pq.pop();
		if (curr_dist > dist[curr_x][curr_y]) continue;

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];
			if (next_x >= n + 2 || next_y >= m + 2 || next_x < 0 || next_y < 0 || map[next_x][next_y] == '*') continue;
			int cost = dist[curr_x][curr_y] + (map[next_x][next_y] == '#'  ? 1:0);
			if (cost < dist[next_x][next_y]) {
				dist[next_x][next_y] = cost;
				pq.push({ -cost,{next_x,next_y} });
 			}
		}
	}
	return dist;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		bool assigned = false;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				map[i][j] = '.';
			}
		}

		for (int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			for (int j = 1; j <= m; j++) {
				map[i][j] = str[j-1];

				//죄수 좌표 저장
				if (str[j-1] == '$' && !assigned) {
					assigned = true;
					psnr1 = { i,j };
				}
				else if(str[j-1] == '$')psnr2 = {i,j};
			}
		}
		vector<vector<int>> p1_dist;
		vector<vector<int>> p2_dist;
		vector<vector<int>> s_dist;

		p1_dist = dijk(psnr1.first, psnr1.second);
		p2_dist = dijk(psnr2.first, psnr2.second);
		s_dist = dijk(0, 0);

		long long ans = INF;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				long long temp;
				if (map[i][j] == '*') continue;
				else if (map[i][j] == '#') temp = p1_dist[i][j] + p2_dist[i][j] + s_dist[i][j] - 2;
				else temp = p1_dist[i][j] + p2_dist[i][j] + s_dist[i][j];
				ans = min(ans, temp);
			}
		}
		cout << ans << "\n";
	}
}