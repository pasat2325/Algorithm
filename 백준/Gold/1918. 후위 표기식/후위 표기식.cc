#include <iostream>
#include <stack>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string expression;
	stack<char>stack;
	cin >> expression;
	expression = '(' + expression + ')';

	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] < 65 || expression[i] > 90) {
			if (expression[i] == '*' || expression[i] == '/')
			{
				if (stack.top() == '*' || stack.top() == '/')
				{
					cout << stack.top();
					stack.pop();
				}
				stack.push(expression[i]);
			}
			else if (expression[i] == '+' || expression[i] == '-')
			{
				while (!stack.empty())
				{
					if (stack.top() == '(')
					{
						break;
					}
					else
					{
						cout << stack.top();
						stack.pop();
					}
				}

				stack.push(expression[i]);
			}
			else if (expression[i] == ')')
			{
				while (!stack.empty())
				{
					if (stack.top() == '(')
					{
						stack.pop();
						break;
					}
					else
					{
						cout << stack.top();
						stack.pop();
					}
				}
			}
			else stack.push(expression[i]);
		}
		else {
			cout << expression[i];
		}
	}
}