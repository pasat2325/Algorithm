#include <iostream>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	int* cows = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> cows[i];
	}

	int leaf_start = 1;
	while (leaf_start < n) {
		leaf_start <<= 1;
	}
	int tree_size = leaf_start << 1;

	pair<int,int>* tree = (pair<int,int>*)malloc(tree_size * sizeof(pair<int,int>));
	
	for (int i = 0; i < tree_size; i++) {
		tree[i].first = 0;
		tree[i].second = 1'000'001;
 	}

	for (int i = 0; i < n; i++) {
		tree[i + leaf_start].first = cows[i];
		tree[i + leaf_start].second = cows[i];
 	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		tree[i].first = max(tree[i << 1].first, tree[i << 1 | 1].first);
		tree[i].second = min(tree[i << 1].second, tree[i << 1 | 1].second);
	}
	while (q--) {
		int a, b;
		cin >> a >> b;

		int L = a + leaf_start - 1;
		int R = b + leaf_start - 1;

		int mx = 0, mn = 1'000'001;
		while (L <= R) {
			if (L & 1) {
				mx = max(tree[L].first, mx);
				mn = min(tree[L++].second, mn);
			}
			if (!(R & 1)) {
				mx = max(tree[R].first, mx);
				mn = min(tree[R--].second, mn);
			}
			L >>= 1;
			R >>= 1;
		}
		cout << mx - mn << "\n";
	}
}