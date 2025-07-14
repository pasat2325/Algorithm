#include <iostream>
using namespace std;

bool erased = false;
bool isP(string& str, int left, int right) {
	while (left < right) {
		if (str[left] != str[right] && !erased) {
			erased = true;
			// str[left]를 지우는 경우 || str[right]를 지우는 경우
			if (isP(str, left + 1, right) || isP(str, left, right - 1)) return true;
			return false;
		}
		else if (str[left] != str[right] && erased) return false;
		else if (str[left] == str[right]) {
			left++; right--;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int left = 0, right = str.length() - 1;
		erased = false;
		bool result = isP(str, left, right);
		if (result && !erased) cout << 0 << "\n";
		else if (result && erased) cout << 1 << "\n";
		else cout << 2 << "\n";
	}
}