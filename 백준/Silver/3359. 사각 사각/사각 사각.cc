#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;//사각형의 개수
	cin >> n;

	//dp를 통해서 문제를 해결한다
	//arr[n][2] 이차원 배열을 선언해서 n개의 사각형이 
	//가로로 놓을 때와(arr[n][0]에 저장) 
	//세로로 놓을 때의 값을 모두 저장한다.(arr[n][1]에 저장)

	//2차원 배열 동적할당. 입력을 받을 arr 배열
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
	}
	//arr배열에 입력을 받는다.
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}

	//2차원 배열 동적할당. 계산을 위한 dp 배열
	int** dp = new int* [n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int[2];
	}
	//첫 사각형을 저장
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];

	//두번째 사각형 부터는 계산을 통해 dp에 저장한다.
	//이전 dp배열에서 선택안한 변과 현재 선택안한 변의 차이를 더해 최댓값을 현재 dp배열에 넣어준다.
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + abs(arr[i - 1][1] - arr[i][1]),
			dp[i - 1][1] + abs(arr[i - 1][0] - arr[i][1])) + arr[i][0];

		dp[i][1] = max(dp[i - 1][0] + abs(arr[i - 1][1] - arr[i][0]),
			dp[i - 1][1] + abs(arr[i - 1][0] - arr[i][0])) + arr[i][1];
	}
	
	//가로로 놓았을 때와 세로로 놓았을 때 더 큰 값을 출력한다.
	cout << max(dp[n - 1][0], dp[n - 1][1]);
}