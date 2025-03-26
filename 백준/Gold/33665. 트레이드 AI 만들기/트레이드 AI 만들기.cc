
#include <iostream>
using namespace std;

int cities[10][4];

int calcCurrProp(int cur_cities[], int loan_cities[], int cash, int A, int B ,bool mine) {
	int prop = 0;
	int c_cities[10] = {0,};

	//도시 가치 계산
	for (int i = 0; i < 10; i++) {
		for (int j = 4 * i; j < 4 * (i + 1); j++) {
			if (mine) {
				if (cur_cities[j] == 1) {
					c_cities[i]++;
				}
			}
			else {
				if (cur_cities[j] == 2) {
					c_cities[i]++;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (c_cities[i]) {
			prop += cities[i][c_cities[i] - 1];
		}
	}
	// 현금 가치 계산
	prop = (int)(prop + (double)cash * ((double)A / 100));

	// 담보 대출 패널티
	for (int i = 0; i < 40; i++) {
		if (mine) {
			if (cur_cities[i] == 1 && loan_cities[i] == 1) prop -= B;
		}
		else
			if (cur_cities[i] == 2 && loan_cities[i] == 1) prop -= B;
	}

	return prop;
}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> cities[i][j];
		}
	}
	int curr_cities[40]; // 현재 소유중인 도시 현황
	int temp_citites[40];

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		curr_cities[i] = str[i] - '0';
	}

	int wt_cities[40]; // 도시 거래 요청 현황
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		wt_cities[i] = str[i] - '0';
	}

	int loan_cities[40]; // 담보 대출 도시 현황
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		loan_cities[i] = str[i] - '0';
	}

	int my_curr_cash, your_curr_cash; // 현재 재산
	cin >> my_curr_cash >> your_curr_cash;

	int i_offered, you_offered; // 거래 요청 현금
	cin >> i_offered >> you_offered;

	int A, B;
	cin >> A >> B;


	int my_curr_prop = calcCurrProp(curr_cities, loan_cities, my_curr_cash, A, B, true);
	int your_curr_prop = calcCurrProp(curr_cities, loan_cities, your_curr_cash, A, B, false);

	// after trade
	for (int i = 0; i < 40; i++) {
		if (wt_cities[i] == 2) {
			curr_cities[i] = 2;	
		}
		else if (wt_cities[i] == 1) {
			curr_cities[i] = 1;

		}
	}
	my_curr_cash += you_offered - i_offered;
	your_curr_cash += i_offered - you_offered;


	int after_my_curr_prop = calcCurrProp(curr_cities, loan_cities, my_curr_cash, A, B, true);
	int after_your_curr_prop = calcCurrProp(curr_cities, loan_cities, your_curr_cash, A, B, false);
	//cout << after_my_curr_prop << " " << after_your_curr_prop;

	int prev_diff = my_curr_prop - your_curr_prop;
	int after_diff = after_my_curr_prop - after_your_curr_prop;
	if (prev_diff <= after_diff) cout << "YES";
	else cout << "NO";
}