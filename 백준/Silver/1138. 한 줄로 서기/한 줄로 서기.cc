#include <iostream>
#include <deque>
#include <stack>
// N <= 10
using namespace std;

void printStack(stack<int> st, int size)
{
	int res[11];
	for (int i = 1; i <= size; i++)
	{
		res[i] = st.top();
		st.pop();
	}
	for (int i = size; i >0; i--)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	stack<int> st;
	deque<int> dq;
	int arr[11];
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = n; i >= 1; i--)
	{
		if (st.size() == arr[i])
		{
			st.push(i);
		}

		else
		{
			while (true)
			{
				if (st.size() == arr[i])
				{
					st.push(i);
					while (!dq.empty())
					{
						st.push(dq.front());
						dq.pop_front();
					}
					break;
				}
				else
				{
					dq.push_front(st.top());
					st.pop();
				}
			}
		}
	}
	printStack(st,st.size());
}