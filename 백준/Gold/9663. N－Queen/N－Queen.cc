#include <iostream>

using namespace std;

int n;
int cnt = 0;
int col[15];

bool check(int line)
{
	// 지금 줄, 지금 칸이 이전의 모든 줄의 퀸의 배치를 따져보았을 때 놓을 수 있는 칸인지를 검사해본다.

	for (int i = 0; i < line; i++)
	{
		//i번째 줄의 퀸과 같은 열인지? i번째 줄의 퀸과 대각선에 있지는 않은지?
		//col[i] 는 i번째 줄의 퀸의 위치, 즉 퀸의 열을 말하는 것이고, col[line]은 현재 배치하고자 하는 칸의 열이다.
		if (col[i] == col[line] || abs(col[i] - col[line]) == line - i)
		{
			return false;
		}
	}
	return true; //모든 for문을 무사히 돌았다면 해당 칸에 배치가 가능하다는 의미다.

}

void solve(int line)
{
	if (line == n) // n줄까지 퀸을 배치했다면 경우의 수를 +1
	{
		cnt++;
	}
	for (int i = 0; i < n; i++)
	{
		col[line] = i; //line번째 줄에 퀸을 배치할 수 있는지 칸을 체크한다.
		if (check(line)) // 해당 줄을 체크해서 true면 다음줄로.. 아니면 다음칸으로
			solve(line + 1);
	}
}

int main()
{	
	cin >> n;
	solve(0);
	cout << cnt;
}