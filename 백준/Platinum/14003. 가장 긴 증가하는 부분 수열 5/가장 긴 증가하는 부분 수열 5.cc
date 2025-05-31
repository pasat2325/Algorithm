#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> L;
int bs(int num) {
	int low = 0;
	int high = L.size() - 1;
	int result = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (L[mid] == num) return mid;
		else if (L[mid] > num) high = mid - 1;
		else {
			result = mid;
			low = mid + 1;
		}
	}
	return result + 1;
}
int main() {
	int n;
	cin >> n;
	vector<int> input(n);
	vector<int> pos(n);
	vector<int> parent(n, -1);
	vector<int> v(n, -1);
	for (int i = 0; i < n; i++) cin >> input[i];
	L.push_back(input[0]);
	pos[0] = 0;
	v[0] = 0;
	for (int i = 1; i < n; i++) {
		if (input[i] > L.back()) {
			pos[i] = L.size();
			parent[i] = v[L.size() - 1];
			L.push_back(input[i]);
			v[L.size() - 1] = i;
		}
		else { 
			// 이분 탐색을 통한 교체
			int idx = bs(input[i]);
			L[idx] = input[i];
			pos[i] = idx;
			if (idx > 0) parent[i] = v[idx - 1];
			v[idx] = i;
		}
	}
	int idx;
	for (int i = n-1; i >= 0; i--) {
		if (pos[i] == L.size() - 1) {
			idx = i;
			break;
		}
	}
	vector<int> result;
	while (idx != -1) {
		result.push_back(input[idx]);
		idx = parent[idx];
	}

	cout << L.size() << "\n";
	reverse(result.begin(), result.end());
	for (auto i : result)cout << i << " ";
}