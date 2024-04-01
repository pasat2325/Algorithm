#include <iostream>
#include <cmath>

using namespace std;

//소수를 판별하는 함수
//소수는 1과 자기 자신만을 약수로 가지는 수임

bool isPrime(int data) {

	//1과 2는 for문을 들어가지 않는다
	if (data == 2) return true;
	if (data == 1) return false;
	for (int i = 2; i <= sqrt(data) + 1; i++) // data를 2부터 루트(data) 까지 나눴을 때 약수가 존재한다면 -> 소수가 아니다. 
	{	
		if (data % i == 0) return false; //나눠떨어지면 -> 약수이다 -> 소수가 아니다.
	}
	return true; // -> 나눠떨어지는 수가 없다면 소수이다.(1과 자기 자신만을 약수로 가진다.)
}

int main() {
	
	int m, n;
	cin >> m >> n;

	for (int i = m; i < n + 1; i++)
	{
		if (isPrime(i)) cout << i << "\n"; //소수인 경우에만 출력한다.
	}
}
