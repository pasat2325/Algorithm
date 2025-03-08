#include <iostream>
#include <deque>
using namespace std;
const int maxn = 1e6 + 1;
int comm[maxn];
int main()
{
	int n;
	cin >> n;
	deque<int> deq;
	for (int i = n; i > 0; i--)
	{
		cin >> comm[i];
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (comm[i] == 1) deq.push_front(i);
		else if (comm[i] == 2)
		{
			if (deq.empty()) deq.push_front(i);
			else
			{
				int temp = deq.front();
				deq.pop_front();
				deq.push_front(i);
				deq.push_front(temp);
			}
		}
		else deq.push_back(i);
	}
	while (!deq.empty())
	{
		cout << deq.front() << " ";
		deq.pop_front();
	}
	return 0;
}