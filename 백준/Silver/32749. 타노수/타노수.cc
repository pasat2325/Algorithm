#include <iostream>
#include <math.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	string str;
	cin >> str;

	int jr = pow(2, n - t);
	string mmax = "0";
	string temp = "";
	int jj = 0;
	for (int i = 0; i < str.length(); i++) {
		jj %= jr;
		jj++;
		//cout << jj << "\n";
		if (jj == jr) {
			temp.push_back(str[i]);
			//cout << mmax << " " << temp << "\n";
			mmax = mmax < temp ? temp : mmax;
			temp.clear();
			continue;
		}
		temp.push_back(str[i]);
	}
	cout << mmax;
}