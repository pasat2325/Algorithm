#include <iostream>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


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
	memset(tree, 0, tree_size * sizeof(int));

	for (int i = 0; i < n; i++) {
		tree[i + leaf_start] = arr[i] & 1 ? 0 : 1;
	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			int pos = b + leaf_start - 1;
			if (!(c & 1)) {
				tree[pos] = 1;
			}
			else tree[pos] = 0;

			for (pos >>= 1; pos >= 1; pos >>= 1) {
				tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
			}
		}
		else {
			int L = b + leaf_start - 1;
			int R = c + leaf_start - 1;
			
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
			if (a == 2) {
				cout << res << "\n";
			}
			else {
				cout << c - b + 1 - res << "\n";
			}
		}
	}
}