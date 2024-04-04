#include <iostream>

using namespace std;


//자릿수를 더해서 리턴 -> 셀프넘버가 아닌 수
int Sum(int n) {
	int ret = n;
	while (n > 0) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int arr[10001] = {0,};
	int num;

	for (int i = 0; i < 10001; i++)
	{
		num = Sum(i); //셀프넘버가 아닌 수를 num에 저장
		if (num < 10001) {
			arr[num] = 1; // 셀프넘버가 아닌 수의 인덱스를 1로 
		}
	}
	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] != 1) {
			cout << i << "\n";
		}
	}
}
