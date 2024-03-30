#include <iostream>
#include <string>
using namespace std;

/*
큐 구조체 구현
구조체 => 기본 접근 지정자가 public, 데이터의 집합을 구현할 때
클래스 => 기본 접근 지정자가 private, 데이터 집합 + 추가적인 로직을 구현할 때
*/

struct Queue
{
	int arr[10000];
	int first;
	int last;

	void init()
	{
		first = 0;
		last = 0;
	}
	void push(int data)
	{
		arr[last++] = data;
	}
	bool empty()
	{
		return (first == last);
	}
	int pop()
	{
		if (empty()) {
			return -1;
		}
		return arr[first++];
	}
	int size()
	{
		return last - first;
	}
	int front()
	{
		if (empty()) {
			return -1;
		}
		return arr[first];
	}
	int back()
	{
		if (empty()) {
			return -1;
		}
		return arr[last - 1];
	}
};

int main()
{
	int N;
	cin >> N;
	
	Queue q;
	q.init();

	for (int i = 0; i < N; i++)
	{
		string command;
		int num;

		cin >> command;

		if (command == "push") {
			cin >> num;
			q.push(num);
		}
		if (command == "pop") {
			cout << q.pop() << "\n";
		}
		if (command == "size") {
			cout << q.size() << "\n";
		}
		if (command == "empty") {
			cout << q.empty() << "\n";
		}
		if (command == "front") {
			cout << q.front() << "\n";
		}
		if (command == "back") {
			cout << q.back() << "\n";
		}
	}
}
