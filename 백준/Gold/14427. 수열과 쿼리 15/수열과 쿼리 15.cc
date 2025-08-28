#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
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
	pair<int,int>* tree = (pair<int,int>*)malloc(tree_size * sizeof(pair<int,int>));
	for (int i = 0; i < tree_size; i++) {
		tree[i].first = INT_MAX;
		tree[i].second = INT_MAX;
	}
	for (int i = 0; i < n; i++) {
		tree[i + leaf_start].first = arr[i];
		tree[i + leaf_start].second = i + 1;
	}
	for (int i = leaf_start - 1; i >= 1; i--) {
		if (tree[i << 1].first <= tree[i << 1 | 1].first) {
			tree[i].first = tree[i << 1].first;
			tree[i].second = tree[i << 1].second;
		}
		else {
			tree[i].first = tree[i << 1 | 1].first;
			tree[i].second = tree[i << 1 | 1].second;
		}
	}

	cin >> m;
	while (m--) {
		int t; cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;

			int pos = a + leaf_start - 1;
			tree[pos].first = b;
			for (pos >>= 1; pos >= 1; pos >>= 1) {
				if (tree[pos << 1].first <= tree[pos << 1 | 1].first) {
					tree[pos].first = tree[pos << 1].first;
					tree[pos].second = tree[pos << 1].second;
				}
				else {
					tree[pos].first = tree[pos << 1 | 1].first;
					tree[pos].second = tree[pos << 1 | 1].second;
				}
			}
		}
		else {
			int L = leaf_start;
			int R = (leaf_start << 1) - 1;

			int idx = INT_MAX;
			int curr = INT_MAX;
			while (L <= R) {
				if (L & 1) {
					if (curr >= tree[L].first) {
						curr = tree[L].first;
						if (idx >= tree[L].second) {
							idx = tree[L].second;
						}
					}
					L++;
				}
				if (!(R & 1)) {
					if (curr >= tree[R].first) {
						curr = tree[R].first;
						if (idx >= tree[R].second) {
							idx = tree[R].second;
						}
					}
					R--;
				}
				L >>= 1;
				R >>= 1;
			}
			cout << idx << "\n";
		}
	}
}