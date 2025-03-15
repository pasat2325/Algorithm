#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct c{
	int g;
	int s;
	int b;
	int cn;
};

bool comp(c a, c b) {
	if (a.g == b.g) {
		if (a.s == b.s)
				return b.b < a.b;
		return b.s < a.s;
	}
	return b.g < a.g;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<c>v(n);
	for (int i = 0; i < n; i++) {
		int cn, g, s, b;
		cin >> cn >> g >> s >> b;
		v[i] = { g,s,b, cn };
	}
	sort(v.begin(), v.end(),comp);
	vector<int> rank(n + 1);
	rank[v[0].cn] = 1;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].g == v[i - 1].g && v[i].s == v[i - 1].s && v[i].b == v[i - 1].b) {
			rank[v[i].cn] = rank[v[i - 1].cn];
		}
		else rank[v[i].cn] = i + 1;
	}
	cout << rank[m];
}