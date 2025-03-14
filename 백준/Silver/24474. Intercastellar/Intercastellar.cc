#include <iostream>
using namespace std;

long long in_sum[200000]; // 인수 누적합을 저장할 배열
int in[200000]; // 최종 인수를 저장할 배열

int bs(int low, int high, long long target) {
	int result = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (in_sum[mid] == target) return in[mid];
		else if (in_sum[mid] < target) {
			low = mid + 1;
		}
		else
		{
			result = in[mid];
			high = mid - 1;
		}
	}
	return result;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int cnt = 1;
		while (num % 2 == 0) {
			num /= 2;
			cnt *= 2;
		}
		if (i == 0) in_sum[i] = cnt;
		else in_sum[i] = in_sum[i - 1] + cnt;
		in[i] = num;

		
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long qr;
		cin >> qr;
		cout << bs(0, n-1, qr) << "\n";
	}
}