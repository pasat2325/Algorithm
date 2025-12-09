#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, T; cin >> N >> T; 
	unordered_map<int, pair<int, int>> um; // key = 학생 번호 :  value {추천 수, 게시 순서}
	unordered_map<int, pair<int, int>> ::iterator it;
	int cnt = 0; // 게시된 학생 수
	for (int i = 0; i < T; i++) {
		int R; cin >> R;
		// 게시되지 않은 학생
		if (um.find(R) == um.end()|| um[R].second == -1) {
			
			if (cnt >= N) {
				int target = -1;
				int min_rep = 1001;
				int oldest = 1001;

				for (it = um.begin(); it != um.end(); it++) {
					if (it->second.second == -1) continue;
					
					int rep = it ->second.first;
					int order = it->second.second;

					if (rep < min_rep || (rep == min_rep && order < oldest)) {
						min_rep = rep;
						oldest = order;
						target = it->first;
					}
				}
				um[target].second = -1;
				um[target].first = 0;
			}
			else {
				cnt++;
			}
			um[R] = { 1,i };

		}
		else {
			um[R].first += 1;
		}
	}
	vector<int> v;
	for (auto j : um) {
		if (j.second.second != -1) v.push_back(j.first);
	}

	sort(v.begin(), v.end());
	for (auto j : v) cout << j << " ";
}