#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> remove; // 사용 불가능 버튼

	//사용 불가능 버튼 입력받기
	for (int i = 0; i < m; i++)
	{
		int del;
		cin >> del;
		remove.push_back(del);
	}

	int diff = 1000000;
	int result = abs(n - 100);

	for (int i = 0; i < 10 + n * 2; i++)
	{
		int temp = i;
		int count = 0;
		while (true)
		{
			if (find(remove.begin(), remove.end(), temp % 10) != remove.end()) //사용 불가능 한 버튼이 있는 경우
			{
				break;
			}
			else 
			{
				temp /= 10;
				count += 1;
				if (temp == 0)
				{
					if (diff > abs(n - i))
					{
						diff = abs(n - i);
						if(result > diff + count)
							result = diff + count;
					}
					break;
				}
			}
		}
	}
	cout << result;


}