#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n; // 피연산자의 개수
	cin >> n;
	string notation; // 후위표기식
	cin >> notation;
	int arr[26];
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		arr[i] = val;
	}

	stack<double> stack;

	for (int i = 0; i < notation.length(); i++)
	{
		if (notation[i] >= 65 && notation[i] <= 90)
		{
			stack.push(arr[notation[i] - 65]);
		}
		else
		{
			double y = stack.top();
			stack.pop();
			double x = stack.top();
			stack.pop();

			if (notation[i] == '+')
			{
				stack.push(x + y);
			}
			else if (notation[i] == '-')
			{
				stack.push(x - y);
			}
			else if (notation[i] == '*')
			{
				stack.push(x * y);
			}
			else
			{
				stack.push(x / y);
			}
		}
	}
	printf("%.2f", stack.top());

}