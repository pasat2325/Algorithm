/*
나이트는 어두운색 -> 밝은색 또는 밝은색 -> 어두운색으로만 점프가 가능하다.
한양이는 본인 차례에 말을 도착지 색과 동일한 색으로 이동만 시켜주면 로하는 절대 도착지에 도달할 수 없다.

즉, 로하는 본인의 첫 선공에 도착지에 도달하지 못하면 평생 승리할 수 없다.
*/

#include <iostream>
using namespace std;


int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
int main() {
	int n, m; cin >> n >> m;
	int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

	bool f = false; 
	for (int i = 0; i < 8; i++) {
		int nx = sx + dx[i];
		int ny = sy + dy[i];
		if (nx == tx && ny == ty) f = true;
	}
	if (f) cout << "LOHA";
	else cout << "HANYANG";
}