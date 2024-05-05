#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;

		int n;
		cin >> n;

		string array;
		cin >> array;

		array = array.substr(1, array.length() - 2);
		
		istringstream ss(array);
		string sub;
		vector<int> v;

		while (getline(ss, sub, ',')) {
			int num = stoi(sub);
			v.push_back(num);
		}
		
		// 뒤집어지지 않은 상태 -> false
		// 뒤집어진 상태 -> true
		// error 는 false 로 초기화

		bool reversed= false; 
		bool error_check = false;
		int po = 0;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'R' && !reversed)
				reversed = 1; //원본 배열에서 뒤집어진 상태
			else if (s[j] == 'R' && reversed)
			{
				reversed = 0; //뒤집어지지 않은 상태
			}
			else if (s[j] == 'D' && v.size() == po)
			{
				error_check = true; // 배열에 원소가 없으므로 error
				break;
			}
			else if (s[j] == 'D' && !reversed) 
			{
				po++;
			}
			else if (s[j] == 'D' && reversed)
			{
				v.pop_back();
			}
		}
		if (error_check) cout << "error" << "\n";
		else 
		{
			cout << "[";
			if (!reversed) {
				for (int j = po; j < v.size(); j++)
				{
					if (j == po) cout << v[j];
					else
					cout << "," << v[j];
				}
			}
			else
			{
				for (int j = v.size() - 1; j >= po; j--)
				{
					
					if (j == v.size()-1) cout << v[j];
					else
						cout << "," << v[j];
					
				}
			}
			cout << "]";
			cout << "\n";
		}
		
	}
}