#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
스택 구조체 구현
구조체 => 기본 접근 지정자가 public, 데이터의 집합을 구현할 때
클래스 => 기본 접근 지정자가 private, 데이터 집합 + 추가적인 로직을 구현할 때
*/

struct Stack
{
	int arr[10000];
	int last;

	void init()
	{
		last = -1;
	}
	void push(int data)
	{
		arr[++last] = data;
	}
	bool empty()
	{
		return (last < 0);
	}
	int pop()
	{
		if (empty()) {
			return -1;
		}
		return arr[last--];
	}
	int size()
	{
		return last + 1;
	}
	int top()
	{
		if (empty()) {
			return -1;
		}
		return arr[last];
	}
};

int main()
{
	int N;
	cin >> N;
	
	Stack s;
	s.init();

	for (int i = 0; i < N; i++)
	{
		string command;
		int num;

		cin >> command;

		if (command == "push") {
			cin >> num;
			s.push(num);
		}
		if (command == "pop") {
			cout << s.pop() << "\n";
		}
		if (command == "size") {
			cout << s.size() << "\n";
		}
		if (command == "empty") {
			cout << s.empty() << "\n";
		}
		if (command == "top") {
			cout << s.top() << "\n";
		}
	}
}

