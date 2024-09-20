#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
vector<int> r[10001];
bool visit[10001];

int dfs(int start) {
	visit[start] = true;
	int ret = 1;

	for (int i = 0; i < r[start].size(); i++) {
		if (visit[r[start][i]] == true) continue;
		ret += dfs(r[start][i]);
	}
	return ret;
}




int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int maxv = 0;
	int ret[10001];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		r[temp2].push_back(temp1);
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		int temp = dfs(i);
		ret[i] = temp;
		maxv = max(temp, maxv);

	}
	
	for (int i = 1; i <= n; i++) {
		if (ret[i] == maxv) cout << i << " ";
	}
	return 0;
}