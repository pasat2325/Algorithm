#include <iostream>
#include <utility>

using namespace std;

int main()
{
	int n;
	int rank = 1;
	pair<int, int> parr[50];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> parr[i].first >> parr[i].second;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) // 모두 비교
		{
			if (parr[i].first < parr[j].first && parr[i].second < parr[j].second) // 덩치가 작을 경우 등수증가
				rank++;
		}
		cout << rank << "\n";
		//한사람을 다른 사람들과 비교 완료 -> 다음사람 비교 시작하기전 rank 초기화
		rank = 1;
	}
}