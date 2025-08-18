#include <iostream>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	long long* arr = (long long*)malloc(n * sizeof(long long));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int leaf_start = 1;
	while (leaf_start < n)
		leaf_start <<= 1;
	int tree_size = leaf_start << 1;

	long long* tree = (long long*)malloc(tree_size * sizeof(tree));
	memset(tree, 0, tree_size * sizeof(tree));

	for (int i = 0; i < n; i++) {
		tree[i + leaf_start] = arr[i];
	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	
	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		int L, R;
		if (x > y) {
			L = y + leaf_start - 1;
			R = x + leaf_start - 1;
		}
		else {
			L = x + leaf_start - 1;
			R = y + leaf_start - 1;
		}

		long long res = 0;
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
		cout << res << "\n";

		int pos = a + leaf_start - 1;
		tree[pos] = b;

		for (pos >>= 1; pos >= 1; pos >>= 1) {
			tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
		}
	}
}