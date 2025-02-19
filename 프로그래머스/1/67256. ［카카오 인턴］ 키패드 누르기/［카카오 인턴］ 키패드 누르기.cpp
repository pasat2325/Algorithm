#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

char shortest_dist(pair<int,int> fingerL, pair<int,int> fingerR, pair<int,int> target, string hand)
{
    int distL = abs(fingerL.first - target.first) + abs(fingerL.second - target.second);
    int distR = abs(fingerR.first - target.first) + abs(fingerR.second - target.second);
    cout << "target 좌표는 " << target.first << "." << target.second << endl;
    cout << "왼손 좌표는 " << fingerL.first << "." << fingerL.second << endl;
    cout << "오른손 좌표는 " << fingerR.first << "." << fingerR.second << endl;
    cout << "왼손과의 거리는 " << distL << "이고," << " 오른손과의 거리는 " << distR << " 입니다."<< endl;
    
    char result;

    if(distL == distR)
        result = hand == "left" ? 'L':'R'; // 거리가 같으면 주 손을 리턴
    else
        result = distL < distR ? 'L':'R'; //더 짧은 손을 리턴
    
    return result;
}

string solution(vector<int> numbers, string hand) {
    vector<pair<int,int>> keypad(12);
    
    for(int i = 0; i < 12; i++)
    {
        keypad[i]= {i / 3 + 1, i % 3 + 1};
    }
    
    pair<int,int> curL = keypad[9];
    pair<int,int> curR = keypad[11];
    string answer = "";
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] ==7)
        {
            curL = keypad[numbers[i] - 1];
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            curR = keypad[numbers[i] - 1];
            answer += 'R';
        }
        else if (numbers[i] == 0)
        {
            char whichHand = shortest_dist(curL, curR, keypad[10], hand);
            if(whichHand == 'L')
            {
                curL = keypad[10];
            }
            else
            {
                curR = keypad[10];
            }
            answer += whichHand;
        }
        else
        {
            char whichHand = shortest_dist(curL, curR, keypad[numbers[i] - 1], hand);
            if(whichHand == 'L')
            {
                curL = keypad[numbers[i] - 1];
            }
            else
            {
                curR = keypad[numbers[i] - 1];
            }
            answer += whichHand;
        }
    }
    return answer;
}