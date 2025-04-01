#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	int arr[26] = {0,};
	for (int i = 0; i < str.length(); i++) {
		if (isupper(str[i])) arr[str[i] - 'A']++;
		else if (islower(str[i])) arr[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 'A') << " | ";
		for (int j = 0; j < arr[i]; j++) cout << "*";
		cout << "\n";
	}
}