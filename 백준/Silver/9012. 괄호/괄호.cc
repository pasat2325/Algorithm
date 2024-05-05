#include <iostream>
#include <stack>
#include <string>
#include <vector>


using namespace std;

class Parenthesis {
public:
	bool type; //열린 괄호면 true, 닫히면 false
	int index; //해당 괄호 인덱스

	Parenthesis(int index, bool type)
	{
		this->index = index;
		this->type = type;
	}

	Parenthesis(int index, char c)
	{
		this->index = index;
		if (c == '(') {
			this->type = true;
		}
		else {
			this->type = false;
		}
	}
};
/**
* 괄호들의 정보가 차례로 배열로 주어질 때, 올바른 괄호 문자열인지 판단
* @param n 괄호문자열의 길이
* @param parentheses 괄호 문자에 대한 배열
* @return
*/

bool isValidParenthesis(const vector<Parenthesis>& parentheses) {
	//현재 짝을 찾지 못한 열린 괄호들만 저장
	//닫힌 괄호가 나오면 스택에서 열린괄호를 삭제해 나간다.
	//맨 위 원소만 삭제 -> 스택변수선언
	stack<Parenthesis> st;

	for (int i = 0; i < parentheses.size(); i++)
	{
		//왼쪽부터 오른쪽의 괄호를 차례로 조회
		//벡터 변수이므로 모든 원소에 접근가능
		Parenthesis p = parentheses[i];

		if (p.type == true) {
			//열린 괄호이면 짝을 찾을때까지 stack 에 보관
			st.push(p);
		}
		else if (p.type == false) {
			//닫힌 괄호면 
			if (st.size() > 0) {
				//가장 마지막에 추가된 열린 괄호와 짝을 맞춰 삭제 가능
				st.pop();
			}
			else {
				//짝을 맞출 수 없다.
				return false;
			}
		}
	}
	if (st.size() > 0) {
		//혹은 st.empty() == 0
		//아직 스택에 짝을 못찾은 열린괄호가 있다면
		return false;
	}
	return true;
}

void process(int caseIndex)
{
	string str;
	cin >> str;

	vector<Parenthesis> parentheses;
	//벡터는 모든 위치의 원소 접근 가능(동적 배열로 사용)
	//스택은 탑 위치의 원소만 접근가능

	for (int i = 0; i < str.length(); ++i)
	{
		parentheses.push_back(Parenthesis(i, str[i]));
	}

	bool isValid = isValidParenthesis(parentheses);

	if (isValid)
	{
		cout << "YES" << "\n"; //괄호 문자열이 올바르다.
	}
	else {
		cout << "NO" << "\n"; //괄호 문자열이 올바르지 않음.
	}
}

int main()
{
	int caseSize; //테스트케이스 개수
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		process(caseIndex);
	}
}