/*
한 디스플레이의 각 LED 위치에 번호를 매기고, 이를 이진수로 나타내면 

0 -> 1110111
1 -> 0010010
2 -> 1011101
3 -> 1011011
4 -> 0111010
5 -> 1101011
6 -> 1101111
7 -> 1010010
8 -> 1111111
9 -> 1111011

가장 많은 반전은 1 to 8 .. 0010010 ^ 1111111 = 1101101 count ones bit = 5번
*/


#include <iostream>
#include <math.h>
using namespace std;


int n, k, p, x, ans;

string sbin[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

// 0 ~ 9 까지의 디스플레이를 이진수로 변환한 결과를 저장하는 배열
int bin[10];

// 0 ~ 9 to 0 ~ 9 반전의 개수를 저장하는 배열
int flops[10][10];

// 각 디스플레이별 숫자
int dis[6];

// 디스플레이를 이진수로 변환하는 함수
void dis_to_bin() {
	for (int i = 0; i <= 9; i++) {
		string s_binary = sbin[i];
		int num = 0;
		for (int j = 0; j < 7; j++) {
			int b = s_binary[j] - '0';
			num += pow(2, 6 - j) * b;
		}
		bin[i] = num;
	}
}

// n to m 변환에서 반전이 필요한 LED의 개수를 계산하는 함수
int count_flops(int n, int m) {
	int x = n ^ m;
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (x & (1 << i))
			cnt++;
	}
	return cnt;
}

// X층 일 때, X층을 디스플레이별로 파싱
void floor_to_dis(int f) {
	int xx = f;
	for (int i = k - 1; i >= 0; i--) {
		dis[i] = xx % 10;
		xx /= 10;
	}
}

int main() {
	dis_to_bin();
	cin >> n >> k >> p >> x;

	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			flops[i][j] = count_flops(bin[i], bin[j]);
		}
	}
	floor_to_dis(x);
	int dis_init[6];

	for (int i = 0; i < k; i++) {
		dis_init[i] = dis[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		floor_to_dis(i);
		int cnt = 0;
		for (int j = 0; j < k; j++) {
			cnt += flops[dis_init[j]][dis[j]];
		}
		if (cnt <= p) {
			ans++;
		}
	}

	cout << ans;
}