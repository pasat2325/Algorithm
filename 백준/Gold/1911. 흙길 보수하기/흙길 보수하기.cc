#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N, L; cin >> N >> L;
	vector<pair<int, int>> holes(N);

	for (int i = 0; i < N; i++) {
		int start, end; cin >> start >> end;
		holes[i] = { start, end };
	}
	sort(holes.begin(), holes.end());

	int cnt = 0;
	int prev = 0; // 이전까지 널빤지가 커버하는 끝 좌표
	for (int i = 0; i < N; i++) {
		int start = holes[i].first;
		int end = holes[i].second;

		// 이전 널빤지가 지금 웅덩이의 끝까지 커버하는 경우
		if (prev >= end) {
			continue;
		}

		// 이전 널빤지와 지금 웅덩이 사이에 거리가 존재하는 경우
		if (prev < start) {
			prev = start;
		}

		// 널빤지가 덮어야할 거리 remain
		int remain = end - prev;
		
		int need;
		if (remain % L == 0) need = remain / L;
		else need = remain / L + 1;

		cnt += need;
		prev += need * L;
	}
    cout << cnt;
}