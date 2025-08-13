#include <iostream>
#include <stack>
#define MAX_N 1'000'001
using namespace std;

int odcn[MAX_N];
int appear[MAX_N];
int arr[MAX_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;


	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		appear[x]++;
	}

	stack<pair<int,int>> s;

	for (int i = 1; i <= n; i++) {
		while (!s.empty() && appear[arr[s.top().second]] < appear[arr[i]]) {
			odcn[s.top().second ] = arr[i];
			s.pop();
		}


		s.push({ arr[i] , i });
	}
	for (int i = 1; i <= n; i++) {
		if (odcn[i] == 0) cout << -1 << " ";
		else cout << odcn[i] << " ";
	}
}