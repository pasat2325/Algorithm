#include <iostream>
#include <cstring>
using namespace std;

const int MAX_C = 1'000'000;

int n;
int candy_count[MAX_C]; // 사탕의 맛에 따른 개수

int bs(int l, int r, const long long tree[], int target) {
	int leaf_start = l;
	int pos = -1;
	while (l <= r) {
		int mid = (l + r) / 2;

		int L = leaf_start;
		int R = mid;

		int res = 0;
		while (L <= R) {
			if (L & 1) {
				res += tree[L++];
			}
			if (!(R & 1)) {
				res += tree[R--];
			}
			L >>= 1;
			R >>= 1;
		}
		//cout << "res: "<< res << "\n";
		if (res >= target) {
			r = mid - 1;
			pos = mid;
		} 
		else if (res < target) {
			l = mid + 1;
		}
	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	// 새로운 맛이 중간 중간 추가될 수 있으므로, 리프노드는 1'000'000개 필요함. 1 ~ 1'000'000개까지.
	int leaf_start = 1;
	while (leaf_start < MAX_C) {
		leaf_start <<= 1;
	}
	int tree_size = leaf_start << 1;

	long long* tree = (long long*)malloc(tree_size * sizeof(long long));
	memset(tree, 0, tree_size * sizeof(long long)); // 초반엔 빈 사탕 상자이므로 모두 0으로 초기화되어야 함.

	while (n--) {
		int a, b, c;
		cin >> a;

		if (a == 1) {
			cin >> b;

			// L = 순위 구간합의 시작지점이므로 고정
			// R = 이분 탐색으로 찾아야할 목표값 => L ~ R 구간합 == b를 만족
			// 이분 탐색의 범위는 L + 1 ~ R 까지.
			int pos = bs(leaf_start, (leaf_start << 1) - 1, tree, b);
			cout << pos - leaf_start + 1 << '\n';

			// 사탕 개수 업데이트
			int out_flavor = pos - leaf_start + 1;
			candy_count[out_flavor]--;
			tree[pos] = candy_count[out_flavor];

			for (pos >>= 1; pos >= 1; pos >>= 1)
				tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];

		}
		else {
			cin >> b >> c;

			// 사탕 개수 업데이트
			candy_count[b] += c;

			int pos = b + leaf_start - 1;
			tree[pos] = candy_count[b];

			for (pos >>= 1; pos >= 1; pos >>= 1)
				tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
		}
	}
}