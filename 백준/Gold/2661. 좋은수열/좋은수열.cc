#include <iostream>
#include <string>

using namespace std;
int n;
string result;
bool found = false;
void solve(string temp, int cnt) {
	if (found) return;
	
	for (int i = 1; i <= cnt / 2; i++) {
		if (temp.substr(cnt - i, i) == temp.substr(cnt - 2 * i, i)) return;
	}
	if (cnt == n) {
		result = temp;
		found = true;
		return;
	}
	solve(temp + "1", cnt + 1);
	solve(temp + "2", cnt + 1);
	solve(temp + "3", cnt + 1);
}

int main() {
	cin >> n;
	solve("", 0);
	cout << result << "\n";
	return 0;
}