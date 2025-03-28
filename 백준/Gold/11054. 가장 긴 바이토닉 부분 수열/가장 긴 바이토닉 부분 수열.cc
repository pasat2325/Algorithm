/*
1. 수열에서 증가하는 부분수열 dp를 구한다.
2. 수열에서 감소하는 부분수열 dp를 구한다.
4. 각 원소 index를 기준으로 본래 수열을 왼쪽 수열과 오른쪽 수열로 나누어서 증감 dp를 사용하여 바이토닉 수열 길이를 구한다.
5. n개의 바이토닉 수열 길이 중 가장 길이가 긴 것을 찾는다.
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int indp[1000];
	int dedp[1000];
	for (int i = 0; i < n; i++) {
		indp[i] = 1;
		dedp[i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j]) {
				indp[i] = max(indp[i], indp[j] + 1);
			}
			if (arr[n - i - 1] > arr[n - j - 1]) {
				dedp[n - i - 1] = max(dedp[n - i - 1], dedp[n - j - 1] + 1);
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		cout << indp[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << dedp[i] << " ";
	}
	cout << "\n";
	*/
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp = indp[i] + dedp[i] - 1;
		ans = temp > ans ? temp : ans;
	}
	cout << ans;
}