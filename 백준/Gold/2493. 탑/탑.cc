#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Tower {
public:
	int index; //타워 인덱스
	int height; //타워 높이
	int targetTowerIndex; //이 타워의 레이저를 수신하는 대상 타워

	Tower(int index, int height)
	{
		this->index = index;
		this->height = height;
		this->targetTowerIndex = 0;
	}

	void setTargetTowerIndex(int targetTowerIndex)
	{
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex()
	{
		return this->targetTowerIndex;
	}
};

/**
* 파라미터로 주어지는 각 타워들에 대해 타겟 타워를 계산
* 
* @param n 타워의 수
* @param towers 왼쪽~오른쪽 순서로 저장된 타워 배열
* 
*/

void findTargetTowers(vector<Tower>& towers)
{
	//현재 다른 타워의 신호를 수신할 가능성이 있는 타워들
	stack<Tower> stk;
	
	//시간 복잡도 O(N)
	for (int i = 0; i < towers.size(); i++)
	{
		Tower& t = towers[i]; //각 타워 t에 대해 차례로 고려
		int targetTowerIndex = 0; //타워 t의 신호를 수신할 후보 (초기값 null)
		
		while (stk.empty() == false && stk.top().height < t.height) {
			//t보다 높이가 낮은 타워들은 이후에도 수신 가능성 x
			stk.pop();
		}
		
		//t 이상의 높이를 가진 타워가 남아있다면
		if (stk.size() > 0)
		{
			//t는 해당 타워를 타겟으로 정하게 된다.
			targetTowerIndex = stk.top().index;
		}
		// 계산한 타겟 정보를 저장한다.
		t.setTargetTowerIndex(targetTowerIndex);

		//t는 마지막에 등장했으므로 다른 타워의 신호를 수신가능

		stk.push(t);
	}
}
int main()
{
	int n;
	cin >> n;

	vector<Tower> towers;

	for (int i = 0; i < n; i++)
	{
		int hi;
		cin >> hi;
		towers.push_back(Tower(i + 1, hi));//인덱스 1부터 저장
	}

	//각 타워가 송신하는 레이저에 대해 타겟을 모두 계산
	findTargetTowers(towers);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) {
			cout << " ";
		}

		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
}