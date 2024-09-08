#include <iostream>

using namespace std;

int main() {

	int index = 0;
	int num = 0;
	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;
		if (atoi(str.c_str())) {
			index = i;
			num = atoi(str.c_str());
		}
	}

	int resultnum;

	resultnum = num + 3 - index;

	if (resultnum % 3 == 0 && resultnum % 5 == 0) cout << "FizzBuzz";
	else if (resultnum % 3 != 0 && resultnum % 5 == 0) cout << "Buzz";
	else if (resultnum % 3 == 0 && resultnum % 5 != 0) cout << "Fizz";
	else cout << resultnum;
}