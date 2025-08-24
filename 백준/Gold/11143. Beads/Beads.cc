#include <iostream>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int b, p, q;
		cin >> b >> p >> q;

		int leaf_start = 1;
		while (leaf_start < b) {
			leaf_start <<= 1;
		}
		int tree_size = leaf_start << 1;

		long long* tree = (long long*)malloc(tree_size * sizeof(long long));
		memset(tree, 0, tree_size * sizeof(long long));

		int x = p + q;
		while (x--) {
			char type; int c, v;
			cin >> type >> c >> v;
			if (type == 'P') {
				int pos = c + leaf_start - 1;

				tree[pos] += v;
				for (pos >>= 1; pos >= 1; pos >>= 1) {
					tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
				}
			}
			else {
				int L = c + leaf_start - 1;
				int R = v + leaf_start - 1;

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
}