#include <iostream>

using namespace std;

int main()
{
	//입력받기
	int N, M, B;
	cin >> N >> M >> B;
	int min_time = 99999999;
	int ground;
	int arr[500][500];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	//0~256 까지 각각의 높이에 대해 use(쌓기) ,remove(제거) 횟수 구하기
	for (int i = 0; i < 257; i++)
	{
		int use = 0, remove = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (i > arr[j][k])
				{
					use += (i - arr[j][k]);
				}
				else if (i < arr[j][k])
				{
					remove += (arr[j][k] - i);
				}
			}
		}

		if (use <= remove + B) //사용하는 블럭의 수가 사용할 수 있는 블럭의 수보다 더 적거나 같은 경우에만 만들 수 있다.
		{
			//시간 구하기
			int Time = use + remove * 2;
			//i 가 계속 증가하므로 
			if (Time <= min_time) { 
				min_time = Time;
				ground = i;
			}
			
		}
	}
	cout << min_time << " " << ground;
}