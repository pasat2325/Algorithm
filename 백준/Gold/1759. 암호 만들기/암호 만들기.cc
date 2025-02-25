#include <iostream>
#include <algorithm>
using namespace std;
int L, C;
char a[26];
int b[256];
void solve(int start, string str)
{
	if (str.length() == L)
	{
		int mo = 0;
		int ja = 0;
		for (int i = 0; i < L; i++)
		{
			if (b[str[i]] == 1) mo++;
			else ja++;
			if (mo >= 1 && ja >= 2)
			{
				cout << str << "\n";
				return;
			}
		}
		return;
	}
	for (int i = start; i < C; i++) solve(i + 1, (str + a[i]));
}
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char x;
		cin >> x;
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			b[x] = 1; // 모음은 1로 표시
		}
		a[i] = x;
	}
	sort(a, a + C);
	solve(0, "");
}