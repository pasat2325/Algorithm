#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void solve()
{
	int k;
	int input;
	int sum = 0;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> input;
		if (input == 0 && v.size() > 0)
		{
			v.erase(v.end() - 1); // 입력이 0이면 끝에 있는 원소를 삭제한다.
		}
		else {
			v.push_back(input); // 0이 아니면 벡터에 저장한다.
		}
	}
	
	if (v.size() == 0)
	{
		cout << 0;
	}
	else {
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		cout << sum;
	}
}

int main()
{
	solve();
}