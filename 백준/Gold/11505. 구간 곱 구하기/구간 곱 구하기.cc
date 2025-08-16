#include <iostream>
#include <math.h>
using namespace std;

const int MOD = 1'000'000'007;
const int MAX_N = 1'000'000;

int n, m, k;
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	// leaf_start = 2^(ceil(log2(n))
	int leaf_start = 1;
	while (leaf_start < n)
		leaf_start <<= 1;
	int size = leaf_start << 1;

	long long* tree = (long long*)malloc(size * sizeof(long long));
	for (int i = 0; i < size; i++) 
		tree[i] = 1;

	// 리프 채우기
	for (int i = 0; i < n; i++)
		tree[leaf_start + i] = arr[i];

	// 부모 노드 채우기
	for (int i = leaf_start - 1; i >= 1; i--)
		tree[i] = (tree[i << 1] * tree[i << 1 | 1]) % MOD;

	int q = m + k;
	while (q--) {
		int qt; cin >> qt;
		if (qt == 1) {
			int idx; long long v;
			cin >> idx >> v;
			int pos = idx + leaf_start - 1;
			tree[pos] = v;
			for (pos >>= 1; pos >= 1; pos >>= 1)
				tree[pos] = (tree[pos << 1] * tree[pos << 1 | 1]) % MOD;
		}
		else {
			int l, r; cin >> l >> r;
			int L = leaf_start + l - 1;
			int R = leaf_start + r - 1;
			long long res = 1;
			while (L <= R) {
				if (L & 1) {
					res *= tree[L];
					res %= MOD;
					L++;
				}
				if (!(R & 1)) {
					res *= tree[R];
					res %= MOD;
					R--;
				}
				L >>= 1;
				R >>= 1;
			}
			cout << res << "\n";
		}
	}

}