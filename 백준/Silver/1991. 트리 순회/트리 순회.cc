#include <iostream>

using namespace std;

pair<char, char> arr[26];

void preorder(char c)
{
	if (c == '.') return;

	cout << c;
	preorder(arr[c - 'A'].first);
	preorder(arr[c - 'A'].second);
}

void inorder(char c)
{
	if (c == '.') return;

	inorder(arr[c - 'A'].first);
	cout << c;
	inorder(arr[c - 'A'].second);
}

void postorder(char c)
{
	if (c == '.') return;

	postorder(arr[c - 'A'].first);
	postorder(arr[c - 'A'].second);
	cout << c;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		arr[parent - 'A'].first = left;
		arr[parent - 'A'].second = right;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}