#include <iostream>
#include <stack>
#define MAX_N 100'000
using namespace std;

long long arr[MAX_N];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	while (1) {

		int n;
		cin >> n;
		
		if (n == 0) break;

		stack<int> st;
		long long max = 0;

		for (int i = 0; i < n; i++) cin >> arr[i];

		for (int i = 0; i < n; i++) {
			
			while (!st.empty() && arr[i] < arr[st.top()]) {

				long long atop = arr[st.top()];
				// 스택이 비워져있다면, 직사각형의 너비는 인덱스와 동일함.
				int w = i;
				st.pop();

				// 스택이 비워져있지 않다면, 직사각형의 너비를 계산
				if (!st.empty()) {
					w = i - st.top() - 1;
				}

				// 직사각형 최대 값 갱신
				if (max < w * atop) {
					max = w * atop;
				}
			}
			st.push(i);
		}

		// 스택에 남은 막대들이 존재한다면
		while (!st.empty()) {
			long long atop = arr[st.top()];
			int w = n;
			st.pop();

			if (!st.empty()) {
				w = n - st.top() - 1;
			}

			if (max < w * atop) {
				max = w * atop;
			}
		}
		cout << max << "\n";
	}
}