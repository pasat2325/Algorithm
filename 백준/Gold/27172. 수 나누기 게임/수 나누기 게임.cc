#include <iostream>
using namespace std;
int arr[1000000];
bool check[1000000];
int in[100000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int max_x = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		max_x = max(max_x, x);
		in[i] = x;
		check[x] = true;
	}
	for (int i = 0; i < n; i++) {
		int temp = in[i];
		for (int j = 2; j <= max_x / temp; j++) {
			int xx = temp * j;
			if (check[xx]) {
				arr[xx]--;
				arr[temp]++;
			}
		}
	}
	for (int i = 0; i < n; i++) cout << arr[in[i]] << " ";
}