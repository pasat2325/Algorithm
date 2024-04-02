#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int n; // 의견의 개수
int k; // 의견

//입력을 받는 함수
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
}


int solve()
{
	// 30 % 절사평균에 따라 제외해야할 사람의 수
	int rmv = round((float)n * 0.15f);
	

	//정렬
	sort(v.begin(), v.end());

	//평균 구하기
	int sum = 0;
	for (int i = rmv; i < n - rmv; i++)
	{
		sum += v[i];
	}
	return round((float)sum / (float)(n-rmv*2));
}

int main()
{
	input();
	if (n == 0) cout << 0;
	else cout << solve();
}