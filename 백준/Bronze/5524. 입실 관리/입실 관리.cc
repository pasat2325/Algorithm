#include <iostream>
using namespace std;
int main() {

	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] < 97) str[i] += 32;
		}
		cout << str << "\n";
	}
}