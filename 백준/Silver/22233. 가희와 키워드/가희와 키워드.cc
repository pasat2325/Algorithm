#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, bool> keywords;
	for (int i = 0; i < n; i++) {
		string keyword; 
		cin >> keyword;

		keywords.insert({ keyword, false });
	}
	int ans = n;
	while (m--) {
		string line;
		cin >> line;
		vector<string> used_keywords;
		
		string temp = "";
		for (int i = 0; i <= line.length(); i++) {
			if (line[i] == ',' || i == line.length()) {
				used_keywords.push_back(temp);
				temp = "";
				continue;
			}
			temp.push_back(line[i]);
		}
		for (auto keyword : used_keywords) {
			if (keywords.find(keyword) == keywords.end()) {
				continue;
			}
			else {
				if (keywords[keyword] == false) {
					keywords[keyword] = true;
					ans--;
				}
			}
		}
		cout << ans << "\n";
	}
}