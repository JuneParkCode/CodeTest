#include <iostream>
#include<algorithm>
#include <functional>         // greater 사용 위해 필요  
#include <vector>
#include<queue>
using namespace std;
/*
	통과 (0.01ms, 3.95MB)
테스트 2 〉	통과 (0.06ms, 3.96MB)
테스트 3 〉	통과 (0.01ms, 3.95MB)
테스트 4 〉	통과 (0.06ms, 3.96MB)
테스트 5 〉	통과 (0.49ms, 3.95MB)
테스트 6 〉	통과 (0.13ms, 3.95MB)
테스트 7 〉	통과 (0.01ms, 3.96MB)
테스트 8 〉	통과 (0.01ms, 3.93MB)
테스트 9 〉	통과 (0.03ms, 3.93MB)
테스트 10 〉	통과 (0.01ms, 3.95MB)
테스트 11 〉	통과 (0.01ms, 3.95MB)
테스트 12 〉	통과 (0.01ms, 3.94MB)
테스트 13 〉	통과 (0.01ms, 3.95MB)
테스트 14 〉	통과 (0.01ms, 3.93MB)

*/
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0;
    int Time = 0; 
    int Truck_weight = 0;
    queue<pair<int, int>> truck_move;

    while (true)
    {
        if (weight >= Truck_weight + truck_weights.at(count))
        {
            truck_move.push(make_pair(truck_weights.at(count), bridge_length + 1 + Time));
            Truck_weight += truck_weights.at(count);
            count++;
            cout<<truck_move.back().first << " "<<truck_move.back().second<<endl;
        }

        if (count >= truck_weights.size())
        {
            answer = truck_move.back().second;
            break;
        }
        else
        {
            Time++;
            if (truck_move.front().second == Time+1)
            {
                Truck_weight -= truck_move.front().first;
                truck_move.pop();
            }
        }

    }

    return answer;
}