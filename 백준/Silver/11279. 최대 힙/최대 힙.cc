#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;


		if(temp == 0){
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else { 
				cout << 0 << "\n";

			}
		
		}
		else {
			q.push(temp);
		}
	}
}