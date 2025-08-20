#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	while (cin >> n >> k) {
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
		for (int i = 0; i < tree_size; i++) {
			tree[i] = 1;
		}

		for (int i = 0; i < n; i++) {
			int x;
			if (arr[i] > 0) x = 1;
			else if (arr[i] < 0) x = -1;
			else if (arr[i] == 0) x = 0;

			tree[i + leaf_start] = x;
		}

		for (int i = leaf_start - 1; i >= 1; i--) {
			tree[i] = tree[i << 1] * tree[i << 1 | 1];
		}

		while (k--) {
			char t;
			int a, b;
			cin >> t >> a >> b;

			if (t == 'C') {
				int pos = a + leaf_start - 1;

				int x;
				if (b > 0) x = 1;
				else if (b < 0) x = -1;
				else if (b == 0) x = 0;
				
				tree[pos] = x;
				for (pos >>= 1; pos >= 1; pos >>= 1) {
					tree[pos] = tree[pos << 1] * tree[pos << 1 | 1];
				}
			}
			else {
				int L = a + leaf_start - 1;
				int R = b + leaf_start - 1;

				int res = 1;
				while (L <= R) {
					if (L & 1) {
						res *= tree[L++];
					}
					if (!(R & 1)) {
						res *= tree[R--];
					}
					L >>= 1;
					R >>= 1;
				}
				if (res > 0) {
					cout << '+';
				}
				else if (res < 0) {
					cout << '-';
				}
				else {
					cout << 0;
				}
			}
		}
		cout << "\n";
	}
}