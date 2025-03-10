#include <iostream>
#include <cstring>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string op = "";
	int m,n;

	int a = 0;
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> op;
		
		if (op == "add") {
			cin >> n;
			a |= (1 << n);
		}
		else if (op == "remove") {
			cin >> n;
			a &= ~(1 << n);
		}
		else if (op == "check") {
			cin >> n;
			if (a & (1 << n))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "toggle") {
			cin >> n;
			if (a & (1 << n)) {  
				a &= ~(1 << n);
			}
			else {             
				a |= (1 << n);     
			}
		}

		else if (op == "all") {
			a = (1 << 21) - 1;
		}
		else if (op == "empty") {
			a = 0;
		}
	}
	return 0;
}