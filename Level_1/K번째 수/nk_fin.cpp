#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto command :commands){
        vector<int> sortVec = array;
        sort(sortVec.begin() + command[0]-1,sortVec.begin()+command[1]);   // sort(begin,end+1) , vector에서 start~end부분만 sort하여 저장한다.
        answer.push_back(sortVec[command[0]+command[2]-2]);                 // 앞선 부분 또한 남아 있기 때문에 command[0] -1 (start) 를 더해야함....
    }
    return answer;
}