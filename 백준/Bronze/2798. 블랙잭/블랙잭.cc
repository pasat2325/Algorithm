#include <iostream>
using namespace std;


int main() 
{
	int N, M;
	int arr[100] = {0, };

	cin >> N >> M;
	
	// 배열에 카드 넘버 저장
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	//브루트포스
	int sum = 0;
	int result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N ; j++)
		{
			for (int k = j + 1; k < N ; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > result && sum <= M) result = sum;
			}
		}
	}
	cout << result << endl;
	
}