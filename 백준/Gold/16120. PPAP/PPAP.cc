/*
문자열 스택
stack.top == 'A' 이고 cur == 'P' 이면서, stack.size() >= 2 일 때
첫 'A'를 pop하고, top을 검사하면서 2번 pop을 한다. 이때 top =='A'가 나오면 NP; (top == 'A'가 나오는 경우 ex: AAAP)
문제 없이 2번 pop했다면 P를 push.

if stack.empty() || stack.size() == 1 PPAP;
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#define MAX_LEN 1000002
using namespace std;
char buf[MAX_LEN];
int main() {
	scanf("%s", &buf);
	stack<char> st;
	int idx = 0;
	bool np = false;
	if (buf[1] == '\0') {
		if (buf[0] == 'P') printf("PPAP\n");
		else printf("NP\n");
		return 0;
	}
	while (true) {
		if (buf[idx] == '\0') break;
		char curr = buf[idx++];
		if (st.empty()) {
			st.push(curr);
			continue;
		}
		if (st.top() == 'A' && curr == 'P' && st.size() >= 3) {
			st.pop();
			for (int i = 0; i < 2; i++) {
				if (st.top() == 'A') {
					np = true;
					break;
				}
				st.pop();
			}
			st.push('P');
		}
		else st.push(curr);
		if (np) break;
	}

	if (st.empty() || st.size() == 1) printf("PPAP\n");
	else printf("NP\n");
	return 0;
	
}