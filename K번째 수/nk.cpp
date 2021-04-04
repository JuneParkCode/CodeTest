#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//submitted...
vector<int> solution(vector<int> array, vector<vector<int>> commands) {d
    vector<int> answer;
    for(auto command :commands){
        vector<int> sortVec;
        int s = command[0]-1;
        int e = command[1]-1;
        int k = command[2]-1;
        for(int i = s; i<=e; i++)
            sortVec.push_back(array[i]);
        sort(sortVec.begin(),sortVec.end());
        answer.push_back(sortVec[k]);
    }
    
    return answer;
}