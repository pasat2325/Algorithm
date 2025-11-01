#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; 
    cin >> n >> k;
    string s; 
    cin >> s;

    string suffix = s.substr(k - 1);   // s[k-1 : ]
    string prefix = s.substr(0, k - 1); // s[0 : k-1]

    if ( (n + k) % 2 == 0 ) {
        reverse(prefix.begin(), prefix.end());
    }

    cout << suffix << prefix;
    return 0;
}