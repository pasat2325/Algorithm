// bruteforce
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t; cin >> t;
	vector<string> cards(4);

	while (t--) {
		for (int i = 0; i < 4; i++) {
			cin >> cards[i];
		}


		string ans = ":(";
		// 4C3 4회 실행
		for (int i = 0; i <= 1; i++) {
			for (int j = i + 1; j <= 2; j++) {
				for (int k = j + 1; k <= 3; k++) {

					string a = cards[i];
					string b = cards[j];
					string c = cards[k];

					//적힌 숫자 
					int aN = a[0] - '0';
					int bN = b[0] - '0';
					int cN = c[0] - '0';
					// 적힌 알파벳
					char aA = a[1];
					char bA = b[1];
					char cA = c[1];

					// 1. 적힌 알파벳이 같으면서 숫자 연속
					if (aA == bA && bA == cA) {
						vector<int> v = { aN, bN, cN };
						sort(v.begin(), v.end());
						if (v[0] + 1 == v[1] && v[1] + 1 == v[2]) ans = ":)";


					}

					// 2. 적힌 알파벳과 숫자가 모두 같다.
					if (aA == bA && bA == cA) {
						if (aN == bN && bN == cN) {
							ans = ":)";
						}


					}

				}
			}
		}
		if (cards[0] == cards[3] && cards[1] == cards[2]) ans = ":)";
		else if (cards[0] == cards[1] && cards[2] == cards[3]) ans = ":)";
		else if (cards[0] == cards[2] && cards[1] == cards[3]) ans = ":)";

		cout << ans << "\n";
	}
}