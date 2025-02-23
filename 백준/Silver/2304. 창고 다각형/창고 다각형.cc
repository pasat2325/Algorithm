#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct pillar {
	int loc;
	int h;
};

bool compare(pillar a, pillar b)
{
	return a.loc < b.loc;
}

int main()
{
	int n;
	int result = 0;
	stack<pillar> stack;
	pillar highest;
	pillar arr[1000];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, h;
		cin >> l >> h;

		arr[i] = { l,h };
	}

	sort(arr, arr + n, compare);

	stack.push(arr[0]);
	highest = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (highest.h <= arr[i].h)
		{
			result += highest.h * (arr[i].loc - highest.loc);
			highest = arr[i];
			while (!stack.empty())
			{
				stack.pop();
			}
		}
		stack.push(arr[i]);
	}

	if (stack.size() >= 2)
	{
		pillar current = stack.top();
		stack.pop();
		while (stack.size() >= 1) {
			if (current.h < stack.top().h)
			{				
				result += current.h * (current.loc - stack.top().loc);
				current = stack.top();
			}
			else stack.pop();
		}
	}

	cout << result + highest.h;
}