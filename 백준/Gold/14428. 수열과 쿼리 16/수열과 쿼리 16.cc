#include <iostream>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int leaf_start = 1;
	while (leaf_start < n) {
		leaf_start <<= 1;
	}
	int tree_size = leaf_start << 1;

	int* tree = (int*)malloc(tree_size * sizeof(int));
	
	for (int i = 0; i < tree_size; i++) tree[i] = INT_MAX;

	for (int i = 0; i < n; i++) {
		tree[i + leaf_start] = arr[i];
	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}

	int q;
	cin >> q;

	while (q--) {
		int type;
		cin >> type;
		
		if (type == 1) {
			int i, v;
			cin >> i >> v;

			int pos = i + leaf_start - 1;

			tree[pos] = v;
			arr[i - 1] = v;
			for (pos >>= 1; pos >= 1; pos >>= 1) {
				tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
			}
		}
		else {
			int i, j;
			cin >> i >> j;

			int L = i + leaf_start - 1;
			int R = j + leaf_start - 1;

			// 1. 해당 구간에서 최소값을 구한다.
			int mn = INT_MAX;
			while (L <= R) {
				if (L & 1) {
					mn = min(mn, tree[L++]);
				}
				if (!(R & 1)) {
					mn = min(mn, tree[R--]);
				}
				L >>= 1;
				R >>= 1;
			}
			//cout << mn << "\n";
			// 2.원본 배열에서 해당 값의 인덱스를 구한다.
			int index;
			for (index = i; index < j; index++) {
				if (arr[index - 1] == mn) { break; }
			}
			cout << index << "\n";
		}
	}
}