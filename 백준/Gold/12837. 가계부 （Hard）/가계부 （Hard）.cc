#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int leaf_start = 1;
	while (leaf_start < n) {
		leaf_start <<= 1;
	}
	int tree_size = leaf_start << 1;

	long long* tree = (long long*)malloc(tree_size * sizeof(long long));
	memset(tree, 0 ,tree_size * sizeof(long long));

	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			int pos = b + leaf_start - 1;

			tree[pos] += c;
			for (pos >>= 1; pos >= 1; pos >>= 1) {
				tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
			}
		}
		else {
			int L = b + leaf_start - 1;
			int R = c + leaf_start - 1;

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
	}

}