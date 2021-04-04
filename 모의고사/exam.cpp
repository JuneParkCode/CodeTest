#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int i[5] {1,2,3,4,5};
    int j[8] {2,1,2,3,2,4,2,5};
    int k[10] {3,3,1,1,2,2,4,4,5,5};
    int people[3] {0,0,0};
    int count = 0;
    for(auto ans : answers){
        people[0]+=(ans==i[count%5]);
        people[1]+=(ans==j[count%8]);
        people[2]+=(ans==k[count%10]);
        ++count;
    }
    int max = 0;
    answer.push_back(0);
    for(int count =0; count <3; count ++){  // 해당 부분을 조금 더 줄일 수 있을텐데 아쉽다.
        if(max < people[count] || max == 0){
            max = people[count];
            answer.pop_back();
            answer.push_back(count+1);
        }
        else if (max == people[count])
            answer.push_back(count+1);
    }
    return answer;
}