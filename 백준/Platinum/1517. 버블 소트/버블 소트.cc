#include <iostream>
#include <vector>
using namespace std;

int n;
long long invcnt = 0;
vector<int> arr;

vector<int> two_arr_sort(vector<int> f, vector<int> s) {
	int f_p = 0; int s_p = 0;
	vector<int> temp;
	while (f_p < f.size() || s_p < s.size()) {
		if (s_p >= s.size() || (f_p < f.size() && f[f_p] <= s[s_p])) {
			temp.push_back(f[f_p]);
			f_p++;
		}
		else {
			temp.push_back(s[s_p]);
			s_p++;
			invcnt += f.size() - f_p;
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
	
	while (n--) {
		int x; cin >> x;
		arr.push_back(x);
	}
	merge_sort(0, arr.size() - 1);
	cout << invcnt;

}