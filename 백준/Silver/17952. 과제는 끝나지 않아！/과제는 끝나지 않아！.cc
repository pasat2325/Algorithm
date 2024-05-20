#include <iostream>
#include <stack>

using namespace std;

struct assignment{
	int score, time;

	assignment(int score, int time)
	{
		this->score = score;
		this->time = time;
	}
};


int main()
{
	int t;
	cin >> t;
	int totalscore = 0;
	stack<assignment> s;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		if (n == 1) {
			int score, time;
			cin >> score >> time;
			
			if (time == 1) {
				totalscore += score;
			}
			else s.push(assignment(score, time - 1));
			
		}
		else {
			if (!s.empty()) {
				s.top().time--;
				if (s.top().time <= 0) {
					totalscore += s.top().score;
					s.pop();
				}
			}
			
		}
	}
	cout << totalscore;
}