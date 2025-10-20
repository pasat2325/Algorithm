#include <iostream>
using namespace std;
int main() {
	int alph[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
	string name1, name2;
	cin >> name1 >> name2;
	string temp = "";
	for (int i = 0; i < name1.length(); i++) {
		temp.push_back(alph[name1[i] - 'A'] +'0');
		temp.push_back(alph[name2[i] - 'A'] +'0');
		
	}
	while (temp.length() > 2) {
		string next_temp = "";
		for (int i = 0; i < temp.length() - 1; i++) {
			int a = temp[i] - '0';
			int b = temp[i + 1] - '0';
			int c = (a + b) % 10;

			char cc = c + '0';
			next_temp.push_back(cc);
		}
		temp = next_temp;
	}
	cout << temp;
}