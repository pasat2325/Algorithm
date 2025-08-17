#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 500'000;
const int MAX_ID = 1'000'001;

int A[MAX_N];
int B[MAX_ID];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		B[id] = i;
	}

	int leaf_start = 1;
	while (leaf_start < n) 
		leaf_start <<= 1;
	int tree_size = leaf_start << 1;

	int* tree = (int*)malloc(tree_size * sizeof(int));
	memset(tree, 0, tree_size * sizeof(int));

	long long res = 0;
	for (int i = 0; i < n; i++) {
		int curr_id = A[i];
		int index = B[curr_id];
		int pos = index + leaf_start;

		// tree update
		tree[pos] = 1;
		for (pos >>= 1; pos >= 1; pos >>= 1) tree[pos]++;

		// 구간합
		int L = index + 1 + leaf_start;
		int R = n - 1 + leaf_start;

		while (L <= R) {
			if (L & 1) {
				res += tree[L];
				L++;
			}
			if (!(R & 1)) {
				res += tree[R];
				R--;
			}
			L >>= 1;
			R >>= 1;
		}
	}
	cout << res;
}