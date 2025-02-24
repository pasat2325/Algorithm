#include <iostream>
#define MOD 900528
using namespace std;

string s;
long long arr[256], ans, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	k = s.size();
	for (int i = 0; i < k; i++) arr[s[i]] = i + 1;
	cin >> s;
	for (char e : s) ans = (ans * k + arr[e]) % MOD;
	cout << ans;
}