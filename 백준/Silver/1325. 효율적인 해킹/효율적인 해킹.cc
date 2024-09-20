#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> tables[10002];
bool visit[10002];

int dfs(int start) {
	visit[start] = true;
	int ret = 1;
	for (int i = 0; i < tables[start].size(); i++) {
		if (visit[tables[start][i]]) continue;
		ret += dfs(tables[start][i]);

	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		tables[temp2].push_back(temp1);
	}

	int maxvalue = 0;
	int ret[10002];
	for (int i = 0; i <= n; i++) {
		fill(&visit[0], &visit[0] + 10002, false);
		int temp = dfs(i);
		ret[i] = temp;
		maxvalue = max(temp, maxvalue);

	}
	
	for (int i = 0; i <= n; i++) {
		if (ret[i] == maxvalue) cout << i << " ";

	}
	return 0;
}