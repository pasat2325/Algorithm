/*
* b = 1, c = 2, a = 3으로 매핑.
* 암호문 bca 순서 = bc 순서 * 암호의 길이 + a의 순서
* 암호문 bc 순서 = b 순서 * 암호의 길이 + c의 순서
* 암호문 b 순서 = 1
* 
* 암호문의 마지막 글자의 순서를 찾을 때, 순차 탐색 시 최대 1,000,000 * 100번 탐색.
* map에 인덱스로 저장.	
* 
* 암호로 사용 가능한 문자를 1부터 순서대로 매핑. (char,int)
*/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, int> map;

string str1, str2;

int solve(int index, int n)
{
	if (index == 0) return map[str2[index]];

	return (solve(index - 1, n) * n + map[str2[index]]) % 900528;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++)
	{
		map.insert({ str1[i - 1], i});
	}

	int n = str2.length();
	cout << solve(str2.length() - 1, str1.length());

}