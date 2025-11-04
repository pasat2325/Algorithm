#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_N = 100'000;

class Edge {
public:
	int node[2]; // start, end
	int cost;

	Edge(int start, int end, int cost) {
		this->node[0] = start;
		this->node[1] = end;
		this->cost = cost;
	}

	bool operator<(const Edge& edge)const {
		return this->cost < edge.cost;
	}
	
	bool operator>(const Edge& edge)const {
		return this->cost > edge.cost;
	}
};

priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

vector<pair<int,int>> xi(MAX_N);
vector<pair<int,int>> yi(MAX_N);
vector<pair<int,int>> zi(MAX_N);

int parent[MAX_N];

int N;


void init_parent() {
	for (int i = 0; i < MAX_N; i++) parent[i] = i;
}

int find_parent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find_parent(parent[x]);
}

bool union_set(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);

	if (x == y) return false; // union fail
	 
	if (x > y) {
		parent[x] = y;
	}
	else {
		parent[y] = x;
	}
	return true; // union success
}

void solve() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int x, y, z; cin >> x >> y >> z;
		xi[i] = { x, i };
		yi[i] = { y, i };
		zi[i] = { z, i };
	}
	
	sort(xi.begin(), xi.begin() + N);
	sort(yi.begin(), yi.begin() + N);
	sort(zi.begin(), zi.begin() + N);

	for (int i = 1; i < N; i++) {
		pq.push(Edge(xi[i - 1].second, xi[i].second, xi[i].first - xi[i - 1].first));
		pq.push(Edge(yi[i - 1].second, yi[i].second, yi[i].first - yi[i - 1].first));
		pq.push(Edge(zi[i - 1].second, zi[i].second, zi[i].first - zi[i - 1].first));
	}
	init_parent();
	
	long long sum = 0;
	int cnt = 0;
	while (!pq.empty()) {
		if (cnt == N - 1) break;
		int start = pq.top().node[0];
		int end = pq.top().node[1];
		int cost = pq.top().cost;
		pq.pop();

		// 간선 연결 성공
		if (union_set(start, end)) {
			sum += cost;
			cnt++;
		}
	}
	cout << sum;
}