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

	pair<int,int>* tree = (pair<int,int>*)malloc(tree_size * sizeof(pair<int,int>));
	
	for (int i = 0; i < tree_size; i++) {
		tree[i].first = INT_MAX;
		tree[i].second = INT_MAX;
	}

	for (int i = 0; i < n; i++) {
		tree[i + leaf_start].first = arr[i];
		tree[i + leaf_start].second = i;
	}

	for (int i = leaf_start - 1; i >= 1; i--) {
		if (tree[i << 1].first > tree[i << 1 | 1].first) {
			tree[i].first = tree[i << 1 | 1].first;
			tree[i].second = tree[i << 1 | 1].second;
		}
		else {
			tree[i].first = tree[i << 1].first;
			tree[i].second = tree[i << 1].second;
		}
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

			tree[pos].first = v;
			for (pos >>= 1; pos >= 1; pos >>= 1) {
				if (tree[pos << 1].first > tree[pos << 1 | 1].first) {
					tree[pos].first = tree[pos << 1 | 1].first;
					tree[pos].second = tree[pos << 1 | 1].second;
				}
				else {
					tree[pos].first = tree[pos << 1].first;
					tree[pos].second = tree[pos << 1].second;
				}
			}
		}
		else {
			int i, j;
			cin >> i >> j;

			int L = i + leaf_start - 1;
			int R = j + leaf_start - 1;

			int mn = INT_MAX;
			int idx = INT_MAX;
			while (L <= R) {
				if (L & 1) {
					if (mn > tree[L].first) {
						mn = tree[L].first;
						idx = tree[L].second;
					}
					else if (mn == tree[L].first) {
						mn = tree[L].first;
						idx = min(idx, tree[L].second);
					}
					L++;
				}
				if (!(R & 1)) {
					if (mn >  tree[R].first) {
						mn = tree[R].first;
						idx = tree[R].second;
					}
					else if (mn == tree[R].first) {
						mn = tree[R].first;
						idx = min(idx, tree[R].second);
					}
					R--;
				}
				L >>= 1;
				R >>= 1;
			}

			cout << idx + 1 << "\n";
		}
	}
}