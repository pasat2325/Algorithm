#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m; cin >> n >> m;

	int* arr = (int*)malloc(n * sizeof(int));
	memset(arr, 0, n * sizeof(int));

	int leaf_start = 1;
	while (leaf_start < n)
		leaf_start <<= 1;
	int tree_size = leaf_start << 1;

	long long* tree = (long long*)malloc(tree_size * sizeof(long long));
	memset(tree, 0, tree_size * sizeof(long long));

	while (m--) {
		int query_type, a, b;
		cin >> query_type >> a >> b;

		if (query_type == 0) { // sum

			int L, R;
			if (a <= b) {
				L = a + leaf_start - 1;
				R = b + leaf_start - 1;
			}
			else {
				L = b + leaf_start - 1;
				R = a + leaf_start - 1;
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
		}
		else if (query_type == 1) { // modify
			int pos = a + leaf_start - 1;

			tree[pos] = b;
			for (pos >>= 1; pos >= 1; pos >>= 1) {
				tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
			}
		}
	}
}