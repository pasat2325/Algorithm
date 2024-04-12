#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n; //수의 개수
vector<int> v; // n개의 정수를 저장하는 벡터


//사용자의 입력을 받는 함수
void input()
{
	int a;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
}

//산술평균을 계산하고 출력하는 함수
void mean()
{
	int sum = 0;
	float avg;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
	}
	avg = (float)sum / n;

	if (abs(round(avg)) == 0)
		cout << 0 << "\n";
	else
		cout << round(avg) << "\n";
}

//중앙값을 출력하는 함수
void median()
{
	cout << v[n / 2] << "\n";
}

//최빈값을 출력하는 함수
//temp := 정수의 빈도수를 일시저장
//count := 일시저장된 빈도수가 최대를 갱신할 경우 count에 저장
//mod := 정수가 이전 값과 같은지 다른지 판단하기 위해 저장하고 사용

void mode()
{

	int temp = 0, count = 0, mod;
	vector<int> modev; //최빈값들을 저장하는 벡터
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			mod = v[i];
			temp = 1, count = 1;
			modev.push_back(v[i]);
		}
		else
		{
			if (mod == v[i]) temp++;
			
			else
			{
				mod = v[i];
				temp = 1;
			}

			if (count < temp)
			{
				modev.clear();
				modev.push_back(v[i]);
				count = temp;
			}
			else if (count == temp)
			{
				modev.push_back(v[i]);
			}
		}
	}
	if (modev.size() > 1) //최빈값이 여러개인 경우
	{
		cout << modev[1] << "\n";
	}
	else cout << modev[0] << "\n";
}

void range()
{
	cout << abs(v[v.size() - 1] - v[0]) << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	input();
	sort(v.begin(), v.end()); // v를 정렬
	mean();
	median();
	mode();
	range();
}