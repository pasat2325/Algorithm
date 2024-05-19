#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//모든 좌표를 전부 탐색할 수 없으므로 중간값을 이용

int main()
{
	int t; // testcase의 개수
	cin >> t;
	vector<int> v_x; // x좌표들을 저장할 벡터
	vector<int> v_y; // y좌표들을 저장할 벡터

	//좌표 입력 받기
	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		v_x.push_back(x);
		v_y.push_back(y);
	}

	//중간값을 구해야 하므로 오름차순으로 좌표정렬
	sort(v_x.begin(), v_x.end());
	sort(v_y.begin(), v_y.end());

	//중간값 구하기
	int median_x, median_y;

	if (t % 2 != 0) {//주어진 좌표의 수가 홀수일 때 
		median_x = v_x[t / 2];
		median_y = v_y[t / 2];
	}
	else {//주어진 좌표의 수가 짝수일 때
		median_x = (v_x[t / 2] + v_x[t / 2 - 1]) / 2;
		median_y = (v_y[t / 2] + v_y[t / 2 - 1]) / 2;
	}


	long long total = 0;

	for (int i = 0; i < t; i++)
	{
		total += abs(v_x[i] - median_x) + abs(v_y[i] - median_y);
	}
	cout << total;
}