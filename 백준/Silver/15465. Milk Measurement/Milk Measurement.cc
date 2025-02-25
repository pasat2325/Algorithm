#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n;
	cin >> n;
	pair<string,int> days[101];
	for (int i = 0; i < n; i++)
	{
		int day, p;
		string name;
		cin >> day >> name >> p;
		days[day] = { name,p };
	}

	unordered_map<string, int> cows;
	string cowNames[3] = {"Mildred", "Elsie", "Bessie"};
	for (auto cow : cowNames)
	{
		cows.insert({ cow,7 });
	}

	int prevGroup[3] = { 1,1,1 };
	int maxMilk = 7;
	int change = 0;
	for (int i = 1; i < 101; i++)
	{
		int curGroup[3] = {0,0,0};
		if (days[i].second != 0)
		{
			cows[days[i].first] += days[i].second;
			int todayMax = 0;
			for (auto cow : cowNames)
			{
				todayMax = todayMax > cows[cow] ? todayMax : cows[cow];
			}
			maxMilk = todayMax;
			for (auto cow : cowNames)
			{
				if (cows[cow] >= maxMilk)
				{
					if (cow == "Mildred") curGroup[0] = 1;
					else if (cow == "Elsie") curGroup[1] = 1;
					else curGroup[2] = 1;
				}
			}
			bool b = false;
			for (int i = 0; i < 3; i++)
			{
				if (prevGroup[i] != curGroup[i]) b = true;
				prevGroup[i] = curGroup[i];
			}
			if (b) change++;
		}
	}
	cout << change;
}
