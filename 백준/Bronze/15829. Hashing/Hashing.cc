#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{	
	string s; //문자 저장
	int n;
	long long m = 1234567891;
	long long r = 1;
	long long sum = 0;
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		sum += ((s[i] - 96) * r) % m;
		r = (r * 31) % m;
	}

	cout << sum % m;

}