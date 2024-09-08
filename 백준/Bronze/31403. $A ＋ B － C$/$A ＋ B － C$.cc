#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;

	cout << a + b - c << endl;

	string d = to_string(a) + to_string(b);
	int f = stoi(d) - c;

	cout << f;
}