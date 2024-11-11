#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> ql;
	priority_queue<int, vector<int>, greater<int>> qg;
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;


		if (temp == 0) {
			if ((!qg.empty() && !ql.empty())) {
				if (qg.top() >= -1 * ql.top()) {
					cout << ql.top() << "\n";
					ql.pop();
				}
				else {
					cout << qg.top() << "\n";
					qg.pop();
				}
				
			}
			else if (!qg.empty() && ql.empty()) {
				cout << qg.top() << "\n";
				qg.pop();
			}
			else if (!ql.empty() && qg.empty()) {
				cout << ql.top() << "\n";
				ql.pop();
			}
			else cout << 0 << "\n";

		}
		

		else {
			if (temp > 0) qg.push(temp);
			else ql.push(temp);
		}
	}
}