#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	int* cranes = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		cin >> cranes[i];
	}

	cin >> m;

	int* boxes = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		cin >> boxes[i];
	}

	sort(cranes, cranes + n, compare);
	sort(boxes, boxes + m, compare);

	bool* used = (bool*)malloc(m * sizeof(bool));
	memset(used, 0, m * sizeof(bool));

	if (cranes[0] < boxes[0]) {
		cout << -1 << "\n";
		return 0;
	}

	int* p = (int*)malloc(n * sizeof(int));
	memset(p, 0, n * sizeof(int));

	int moved = 0;
	int time = 0;
	while (moved != m) {
		for (int i = 0; i < n; i++) {
			for (int j = p[i]; j < m; j++) {
				if (!used[j] && cranes[i] >= boxes[j]) {
					used[j] = true;
					moved++;
					break;
				}
				p[i]++;
			}
		}
		time++;
	}
	cout << time;
}