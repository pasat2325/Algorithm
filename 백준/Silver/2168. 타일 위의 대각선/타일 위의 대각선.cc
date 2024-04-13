#include <iostream>
#include <time.h>

using namespace std;

//gcd를 구하기 위해 유클리드 호제법을 사용한다.
int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

/**
* 규칙
* 1. 만약 대각선이 정확히 정사각형의 모서리를 지나는 격자점이 존재하지 않는 경우
* 잘려지는 정사각형의 개수는 H + W - 1 이다.
* 2.격자점이 존재하는 경우에는
* 잘려지는 정사각형의 개수는 H + W - 1 - 격자점의 개수 (또는 최대공약수) 이다.
*/

int main()
{
	int n, m; // 가로,세로 길이를 저장
	cin >> n >> m;

	int g = gcd(n, m); //최대공약수를 구해 g에 저장



	cout << ((n / g + m / g - 1) * g) << endl;

	return 0;
	
}