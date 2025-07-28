#include<iostream>
#include<stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long ans = 0;
	cin >> n;
	stack<pair<int,int>> st;
	while (n--) {
		int curr;
		cin >> curr;
		if (!st.empty()) {
			if (st.top().first <= curr) {
				int t = 1;
				while (true) {
					if (st.empty()) break;
					else if (st.top().first > curr) {
						ans++;
						break;
					}
					ans += st.top().second;
					if (st.top().first == curr) t += st.top().second;
					st.pop();
				}
				st.push({ curr, t });
			}
			else {
				ans++;
				st.push({ curr,1 });
			}
		}
		else {
			st.push({ curr,1 });
		}
	}
	cout << ans << "\n";
	return 0;
}