#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
	string joi;
	cin >> joi;
	stack<char>stack;
	int ans = 0;
	for (int i = 0; i < joi.length(); i++)
	{
		if (joi[i] == 'J')
		{
			if (!stack.empty() && stack.top() == 'I')
			{
				int J = 0, O = 0, I = 0;
				int mxk = 0;

				while (!stack.empty())
				{
					if (stack.top() == 'J') J++;
					else if (stack.top() == 'O') O++;
					else I++;
					stack.pop();
				}
				stack.push('J');
				if (O > J || O > I) continue;
				mxk = min({ J,O,I });
				ans = max(ans, mxk);
			}
			else if (stack.empty() || stack.top() == 'J') stack.push('J');
			else if (!stack.empty() && stack.top() == 'O')
			{
				while (!stack.empty())
				{
					stack.pop();
				}
				stack.push('J');
			}
		}
		else if (joi[i] == 'O')
		{
			if (!stack.empty() && (stack.top() == 'J' || stack.top() == 'O')) stack.push('O');
			else if (!stack.empty() && stack.top() == 'I')
			{
				int J = 0, O = 0, I = 0;
				int mxk = 0;
				while (!stack.empty())
				{
					if (stack.top() == 'J') J++;
					else if (stack.top() == 'O') O++;
					else I++;
					stack.pop();
				}
				if (O > J || O > I) continue;
				mxk = min({ J,O,I });
				ans = max(ans, mxk);
			}
		}
		else
		{
			if (i == joi.length() - 1 && !stack.empty() && stack.top() != 'J')
			{
				int J = 0, O = 0, I = 0;
				int mxk = 0;
				while (!stack.empty())
				{
					if (stack.top() == 'J') J++;
					else if (stack.top() == 'O') O++;
					else I++;
					stack.pop();
				}
				if (O > J || O > I + 1) continue;
				mxk = min({ J,O,I + 1 });
				ans = max(ans, mxk);
			}
			else if (!stack.empty() && (stack.top() == 'O' || stack.top() == 'I')) stack.push('I');
			else if (!stack.empty() && stack.top() == 'J')
			{
				while (!stack.empty())
				{
					stack.pop();
				}
			}
		}
	}
	cout << ans;
}