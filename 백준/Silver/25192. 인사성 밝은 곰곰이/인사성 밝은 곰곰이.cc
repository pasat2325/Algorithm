#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	unordered_map<string, bool> M;
	unordered_map<string, bool> ::iterator it;

	int ans = 0;
	while (n--) {
		string str; cin >> str;
		
		if (str == "ENTER") {
			M.clear();
		}
		else {
			if (M.find(str) == M.end()) {
				M.insert({ str, true });
				ans++;
				continue;
			}
		}
	}
	cout << ans;
}