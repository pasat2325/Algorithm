#include <iostream>
#include <vector>
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

	for (int i = 0; i < n; i++) cin >> input[i];
	L.push_back(input[0]);
	for (int i = 1; i < n; i++) {
		if (input[i] > L.back()) {
			L.push_back(input[i]);
		}
		else { 
			// 이분 탐색을 통한 교체
			int idx = bs(input[i]);
			L[idx] = input[i];
		}
	}
	cout << L.size();
}