#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int,int>>chicken;
vector<pair<int,int>>house;
vector<vector<int>>comb;

// 맵상의 치킨집에 번호를 매기고, 그 조합들을 comb 벡터에 저장한다.
void combination(int start, vector<int> v, int n, int k) {
    if (v.size() == k) {
        comb.push_back(v);
        return;
    }

    for (int i = start + 1; i < n; i++) {
        v.push_back(i);
        combination(i, v, n, k);
        v.pop_back();
    }
    return;
}

int main() {
    int n; // 맵의 크기 n*n;
    int k; // 고르는 치킨집의 개수
    vector<int> v;
    int dis[101][14]; //집과 치킨집의 거리를 저장하는 배열 ex) dis[0][1]은 0번집과 1번 치킨집의 거리를 저장
    cin >>n >> k;

    //맵상의 집과 치킨집의 좌표를 저장.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1) house.push_back({ i, j });
            else if (x == 2) chicken.push_back({ i,j });
        }
    }

    //맵상의 모든 집과 치킨집 사이의 거리를 저장.
    for (int i = 0; i < house.size(); i++)
    {
        for (int j = 0; j < chicken.size(); j++)
        {
            dis[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
        }
    }

    int cn = chicken.size();
    combination(-1, v, cn, k); // 어떤 치킨 집을 고를 것인가? 조합 종류를 벡터에 저장한다. ex(0,1,2)

    int result = INT_MAX;
    
    for (int i = 0; i < comb.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < house.size(); j++)
        {
            int mindis;
        
            vector<int>disvec;
            for (int l = 0; l < k; l++)
            {
                
                disvec.push_back(dis[j][comb[i][l]]);
                sort(disvec.begin(), disvec.end());
            }
            mindis = disvec[0];
            temp += mindis;

        }
        if (temp < result) result = temp;
    }
    cout << result;

    

    return 0;
}