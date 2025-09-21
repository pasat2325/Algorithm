#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v1;
	vector<pair<int, int>> v2;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v1.push_back({ x1,y1 });
		v2.push_back({ x2,y2 });
	}
	int a, b;
	cin >> a >> b;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		x1 = v1[i].first;
		y1 = v1[i].second;
		x2 = v2[i].first;
		y2 = v2[i].second;

		int height = y2 - y1;
		long long cal1 = (long long)x1 * (long long)a + (long long)b -(long long)y1;
		long long cal2 = (long long)x2 * (long long)a + (long long)b - (long long)y1; 
		long long cal3 = cal1 + cal2;

		if (cal3 <= height) cnt++;
	}
	cout << cnt;
}