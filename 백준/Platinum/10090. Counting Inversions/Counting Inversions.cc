#include <iostream>
#include <vector>
using namespace std;

int n;
long long invcnt = 0;
vector<int> arr;

// 1'000'000

vector<int> two_arr_sort(vector<int> first, vector<int> second) {
	int f_p = 0; int s_p = 0;

	vector<int>temp;

	while (f_p < first.size() || s_p < second.size()) {
		if (s_p >= second.size() || (f_p < first.size() && first[f_p] <= second[s_p])) {
			temp.push_back(first[f_p]);
			f_p++;
		}
		else {
			temp.push_back(second[s_p]);
			s_p++;

			invcnt += first.size() - f_p;
		}
	}
	return temp;
}

vector<int> merge_sort(int l, int r) {
	if (l == r) {
		vector<int> temp = { arr[l] };
		return temp;
	}

	int m = (l + r) / 2;

	vector<int> first = merge_sort(l, m);
	vector<int> second = merge_sort(m + 1, r);
	return two_arr_sort(first, second);
}

int main() {
	cin >> n;

	while(n--) {
		int x; cin >> x;
		arr.push_back(x);
	}
	merge_sort(0, arr.size() - 1);
	cout << invcnt;
}