#include <iostream>

using namespace std;


int arr[129][129] = { 0, };
int white = 0;
int blue = 0;


void func(int x, int y, int n)
{

	int count = 0;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] == 1) count++;
		}
	}

	if (count == n * n) blue++; //all blue
	else if (count == 0) white++; //all white
	else
	{
		func(x, y, n / 2); //좌측상단 
		func(x , y + n /2, n / 2); //우측상단
		func(x + n / 2, y, n / 2); //좌측하단
		func(x + n / 2, y + n / 2, n / 2); //우측하단
	}
	return;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	func(0, 0, n);

	cout << white <<"\n" << blue;
}