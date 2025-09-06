#include <iostream>
#include <cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	int* houses = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) 
		cin >> houses[i];

	int leaf_start = 1;
	while (leaf_start < n)
		leaf_start <<= 1;
	int tree_size = leaf_start << 1;
	long long* tree = (long long*)malloc(tree_size * sizeof(long long));
	memset(tree, 0, tree_size * sizeof(long long));
	for (int i = 0; i < n; i++) 
		tree[i + leaf_start] = houses[i];
	for (int i = leaf_start - 1; i >= 1; i--)
		tree[i] = tree[i << 1] + tree[i << 1 | 1];

	int t; cin >> t;
	while (t--) {
		char type;
		int a, b;
		cin >> type >> a >> b;
		if (type == 'R') {
			int L = a + leaf_start - 1;
			int R = b + leaf_start - 1;
			long long res = 0;
			while (L <= R) {
				if (L & 1) 
					res += tree[L++];
				if (!(R & 1))
					res += tree[R--];
				L >>= 1;
				R >>= 1;
			}
			cout << res << "\n";
		}
		else {
			int pos = a + leaf_start - 1;
			tree[pos] += b;
			for (pos >>= 1; pos >= 1; pos >>= 1)
				tree[pos] += b;
		}
	}

}