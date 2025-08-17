#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int MAX_N = 100'000;
int a[MAX_N];
int n,m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int leaf_start = 1;
	while (leaf_start < n) {
		leaf_start <<= 1;
	}
	int tree_size = leaf_start << 1;
	
	int* tree = (int*)malloc(tree_size * sizeof(int));
	for (int i = 0; i < tree_size; i++) {
		tree[i] = INT_MAX;
	}

	for (int i = 0; i < n; i++) {
		tree[leaf_start + i] = a[i];
	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		int L = l + leaf_start - 1;
		int R = r + leaf_start - 1;

		int ans = INT_MAX;
		while (L <= R) {
			if (L & 1) {
				ans = min(ans, tree[L++]);
			}
			if (!(R & 1)) {
				ans = min(ans, tree[R--]);
			}
			L >>= 1;
			R >>= 1;
		 }
		cout << ans << "\n";
	}
	
}