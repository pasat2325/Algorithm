#include <iostream>
using namespace std;

class Grid {
public:
	int scale_6 = 0;
	int scale_5 = 0;
	int scale_4 = 0;
	int scale_3 = 0;
	int scale_2 = 0;
	int scale_1 = 0;
	int remain = 0;

	void update_remain() {
		int total = scale_6 * 36 + scale_5 * 25 + scale_4 * 16 + scale_3 * 9 + scale_2 * 4 + scale_1;
		remain = 36 - total;
	}
};

int main() {
	int s6, s5, s4, s3, s2, s1; cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;

	int cnt = 0;
	while (s6--) {
		cnt++;
	}

	while (s5--) {
		cnt++;
		if (s1) {
			s1 -= min(s1, 11);
		}
	}

	while (s4--) {
		cnt++;
		Grid grid;
		grid.scale_4 = 1;
		grid.update_remain();

		if (s2) {
			grid.scale_2 = min(s2, 5);
			s2 -= min(s2, 5);
			grid.update_remain();
		}

		if (s1) {
			s1 -= min(s1, grid.remain);
		}
	}

	while (s3) {
		Grid grid;
		grid.scale_3 = min(s3, 4);
		s3 -= min(s3, 4);
		grid.update_remain();

		if (s2) {
			if (grid.scale_3 == 1) {
				grid.scale_2 = min(s2, 5);
				s2 -= min(s2, 5);
				grid.update_remain();
			}
			else if (grid.scale_3 == 2) {
				grid.scale_2 = min(s2, 3);
				s2 -= min(s2, 3);
				grid.update_remain();
			}
			else if (grid.scale_3 == 3) {
				grid.scale_2 = 1;
				s2 -= 1;
				grid.update_remain();
			}
		}
		if (s1) {
			s1 -= min(s1, grid.remain);
		}
		cnt++;
	}
	while (s2) {
		Grid grid;
		grid.scale_2 = min(s2, 9);
		s2 -= min(s2, 9);
		grid.update_remain();

		if (s1) {
			s1 -= min(s1, grid.remain);
		}
		cnt++;
	}
	while (s1) {
		s1 -= min(s1, 36);
		cnt++;
	}

	cout << cnt;
}