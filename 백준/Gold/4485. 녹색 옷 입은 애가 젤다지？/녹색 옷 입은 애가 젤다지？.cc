#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int map[125][125];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tc;

void print_result(int index, int result) {
	printf("Problem %d: %d\n", index, result);
}

vector<vector<int>> dijk(int sx,int sy) {
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> weight(125,vector<int>(125,INF));
	pq.push({ -map[sx][sy],{sx,sy}});
	weight[sx][sy] = map[sx][sy];
	while (!pq.empty()) {
		int curr_weight = -pq.top().first;
		int curr_x = pq.top().second.first;
		int curr_y = pq.top().second.second;
		pq.pop();
		if (weight[curr_x][curr_y] < curr_weight) continue;

		for (int i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];
			if (next_x >= tc || next_y >= tc || next_x < 0 || next_y < 0) continue;
			int next_weight = curr_weight + map[next_x][next_y];
			if (weight[next_x][next_y] > next_weight) {
				weight[next_x][next_y] = next_weight;
				pq.push({ -next_weight,{next_x,next_y} });
			}
		}
	}
	return weight;
}
int main() {
	int index = 0;
	while (true) {
		scanf("%d", &tc);
		if (tc == 0) break;
		index++;

		for (int i = 0; i < tc; i++) {
			for (int j = 0; j < tc; j++) {
				int x;
				scanf("%d", &x);
				map[i][j] = x;
			}
		}
		vector<vector<int>> result_vec = dijk(0, 0);
		print_result(index, result_vec[tc - 1][tc - 1]);
	}
}
