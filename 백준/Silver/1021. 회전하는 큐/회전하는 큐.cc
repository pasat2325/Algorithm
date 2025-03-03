#include <iostream>
#include <deque>
using namespace std;
int n, m;
int ans;
deque<int> deq;

void moveLeft(int target)
{
	while (true)
	{
		int p = deq.front();
		deq.pop_front();
		if (p != target)
		{
			deq.push_back(p);
			ans++;
		}
		else break;
	}
}
void moveRight(int target)
{
	while (true)
	{
		int p = deq.front();
		int b = deq.back();
		if (p != target)
		{
			deq.pop_back();
			deq.push_front(b);
			ans++;
		}
		else
		{
			deq.pop_front();
			break;
		}
	}
}
bool nearLeft(int target)
{
	int index = 0;
	for (int i = 0; i < deq.size(); i++)
	{
		if (deq[i] == target) index = i;
	}
	if (index <= deq.size() / 2) return true;
	else return false;

}
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) deq.push_back(i + 1);
	int arr[50];
	for (int i = 0; i < m; i++) cin >> arr[i]; 
	for (int i = 0; i < m; i++)
	{
		if (nearLeft(arr[i]))
		{
			moveLeft(arr[i]);
		}
		else
		{
			moveRight(arr[i]);
		}
	}
	cout << ans;
}