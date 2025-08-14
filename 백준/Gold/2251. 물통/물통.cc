#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
bool bl[201][201][201];
bool cbl[201];
vector<int> res;

void solve(int aa, int bb, int cc) {
	if (bl[aa][bb][cc]) {
		return;
	}

	if (aa == 0) {
		if(!cbl[cc]){
			res.push_back(cc);
			cbl[cc] = true;
		}
	}

	bl[aa][bb][cc] = true;

	if (aa) {
		int naa, nbb, ncc;
		if (aa + bb > b) {
			nbb = b;
			naa = aa - (b - bb);
		}
		else {
			nbb = bb + aa;
			naa = 0;
		}

		if(!bl[naa][nbb][cc]) solve(naa, nbb, cc);


		if (aa + cc > c) {
			ncc = c;
			naa = aa - (c - cc);
		}
		else {
			ncc = cc + aa;
			naa = 0;
		}

		if (!bl[naa][bb][ncc]) solve(naa, bb, ncc);
	}
	
	if (bb) {
		int naa, nbb, ncc;
		if (bb + aa > a) {
			naa = a;
			nbb = bb - (a - aa);
		}
		else {
			naa = aa + bb;
			nbb = 0;
		}

		if (!bl[naa][nbb][cc]) solve(naa, nbb, cc);

		if (bb + cc > c) {
			ncc = c;
			nbb = bb - (c - cc);
		}
		else {
			ncc = cc + bb;
			nbb = 0;
		}

		if (!bl[aa][nbb][ncc]) solve(aa, nbb, ncc);
	}

	if (cc) { 
		int naa, nbb, ncc;
		if (cc + aa > a) {
			naa = a;
			ncc = cc - (a - aa);
		}
		else {
			naa = aa + cc;
			ncc = 0;
		}

		if (!bl[naa][bb][ncc]) solve(naa, bb, ncc);

		if (cc + bb > b) {
			nbb = b;
			ncc = cc - (b - bb);
		}
		else {
			nbb = bb + cc;
			ncc = 0;
		}

		if (!bl[aa][nbb][ncc]) solve(aa, nbb, ncc);
	}
}

int main() {
	cin >> a >> b >> c;
	solve(0, 0, c);
	sort(res.begin(), res.end());
	for (auto i : res) cout << i << " ";
}









