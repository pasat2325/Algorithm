#include <iostream>
using namespace std;

class Deque {
private:
	int* deque = {};
	int begin, end;
public:
	Deque(int n) {
		deque = new int[n];
		begin = -1;
		end = -1;
	}
	void push_front(int num);
	void push_back(int num);
	void pop_front();
	void pop_back();
	void size();
	bool empty();
	void front();
	void back();

	~Deque() {
		delete[] deque;
	}
};

void Deque::push_front(int num) {
	if (empty()) {
		begin = 0;
		end = 0;
		deque[begin] = num;
	}
	else {
		for (int i = end; i >= begin; i--) {
			deque[i + 1] = deque[i];
		}
		deque[begin] = num;
		end++;
	}
}

void Deque::push_back(int num) {
	if (empty()) {
		begin = 0;
		end = 0;
		deque[begin] = num;
	}
	else {
		end++;
		deque[end] = num;
	}
}

void Deque::pop_front() {
	if (empty()) {
		cout << -1 << "\n";
	}
	else {
		cout << deque[begin] << "\n";
		deque[begin] = NULL;
		begin++;
	}
}

void Deque::pop_back() {
	if (empty()) {
		cout << -1 << "\n";
	}
	else {
		cout << deque[end] << "\n";
		deque[end] = NULL;
		end--;
	}
}

void Deque::size() {
	if (empty()) {
		cout << 0 << "\n";
	}
	else {
		cout << end - begin + 1 << "\n";
	}
}

bool Deque::empty() {
	if (begin == -1 || begin > end) {
		return true;
	}
	else return false;
}

void Deque::front() {
	if (empty()) {
		cout << -1 << "\n";
	}
	else
		cout << deque[begin] << "\n";
}

void Deque::back() {
	if (empty()) {
		cout << -1 << "\n";
	}
	else
		cout << deque[end] << "\n";
}

int main()
{
	int n;
	cin >> n;

	Deque dq(n);

	for (int i = 0; i < n; i++)
	{
		
		string command;
		cin >> command;
		
		if (command == "push_front")
		{
			int num;
			cin >> num;
			dq.push_front(num);
		}

		else if (command == "push_back")
		{
			int num;
			cin >> num;
			dq.push_back(num);
		}

		else if (command == "pop_front")
		{
			dq.pop_front();
		}

		else if (command == "pop_back")
		{
			dq.pop_back();
		}

		else if (command == "size") {
			dq.size();
		}

		else if (command == "empty") {
			cout << dq.empty() << endl;
		}

		else if (command == "front") {
			dq.front();
		}

		else if (command == "back") {
			dq.back();
		}
	}
}