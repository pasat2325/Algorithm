#include <iostream>
using namespace std;

int main()
{
	int p;
	cin >> p;

	int sarr[6] = { 0, };

	for (int i = 0; i < 6; i++) {
		cin >> sarr[i];
	}

	int gt, gp;
	cin >> gt >> gp;

	int at = 0;
	for (int i = 0; i < 6; i++) {
		int a;

		if (sarr[i] == 0) a = 0;
		else if (sarr[i] <= gt) a = 1;
		else if (sarr[i] % gt == 0) a = sarr[i] / gt;
		else a = sarr[i] / gt + 1;
		at += a;
	}

	cout << at << endl;
	cout << p / gp <<" " << p % gp;
}