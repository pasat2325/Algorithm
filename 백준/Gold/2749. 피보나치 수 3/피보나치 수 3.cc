#include <iostream>
#include <map>
#define mod 1000000
using namespace std;
map<long, long> mp;

long long solve(long long n)
{
	if (mp[n]) return mp[n];

	long long result;
	if (n % 2 == 0) result = (solve(n / 2) * (solve(n / 2 + 1) + solve(n / 2 - 1))) % mod;
	else result = (((solve((n + 1) / 2) * solve((n + 1) / 2)) %mod) + ((solve((n - 1) / 2) * solve((n - 1) / 2))%mod)) % mod;

	return mp[n] = result;
}

int main()
{
	long long n;
	cin >> n;
	mp[0] = 0;
	mp[1] = 1;
	mp[2] = 1;
	cout << solve(n);
}