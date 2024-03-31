#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//이분탐색과 매개변수탐색

int n;
long long m; // 나무의 수, 가져가야할 나무의 길이
vector<int> v; // 나무의 길이를 저장하는 벡터

void input()//입력 받기
{
	cin >> n >> m;
	v.assign(n, 0); // n개 만큼 0으로 동적 할당
	for (int i = 0; i < n; i++)
	{
		cin >> v[i]; // 나무의 길이 입력받기.
	}
}

//나무의 길이를 매개변수로 탐색하기
bool isPossible(long long tree) {
	long long cnt = 0; // 가져갈 수 있는 나무의 길이

	for (int i = 0; i < n; i++)
	{
		if(tree < v[i]) cnt += v[i] - tree; // 가져갈 수 있는 나무의 길이 저장
		
		//만약 가져갈 수 있는 나무의 길이가 m 이상인 경우 배열오른쪽에서 탐색. (가져갈 수 있는 나무의 길이는 줄어듬)
	}
	if (cnt >= m) {
		return true;
	}
	else return false;
}

//이분 탐색하기
void bsearch() {
	sort(v.begin(), v.end());//이분탐색을 위해 정렬
	
	unsigned int low = 1;
	unsigned long long high = v[v.size() - 1];//가져갈 수 있는 최대 길이는 가장 긴 나무의 길이
	unsigned long long result = 0;

	while (low <= high) {
		unsigned long long mid = (low + high) / 2;
		//매개변수 탐색을 이용한다.
		//true 이면 오른쪽 배열에서 최댓값을 찾는다.
		//false 이면 왼쪽 배열에서 더 작은 값을 찾는다.
		if (isPossible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	bsearch();
	return 0;
}

