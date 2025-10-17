#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<string, int>M;
	vector<string> names;
	string name;
	int total = 0;
	while (getline(cin, name)) {
		if (name.empty()) continue;
		if (M.find(name) != M.end()) {
			M[name] += 1;
		}
		else {
			M[name] = 1;
			names.push_back(name);
		}
		total += 1;
	}
	sort(names.begin(), names.end());
	for (auto c : names) {
		int cnt = M[c];
		double freq = (double)cnt / (double)total;
		freq *= 100;
		printf("%s %.4f\n", c.c_str(), freq);
	}

}