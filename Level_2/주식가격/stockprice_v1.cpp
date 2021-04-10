#include <string>
#include <vector>

/*
테스트 1 〉	통과 (26.86ms, 24.3MB)
테스트 2 〉	통과 (18.58ms, 18.9MB)
테스트 3 〉	통과 (30.72ms, 26.8MB)
테스트 4 〉	통과 (21.77ms, 21.1MB)
테스트 5 〉	통과 (15.49ms, 16.2MB)
*/
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    // 가장 간단한 방법...
    for(int i=0; i<prices.size(); i++){
        bool isUpdated =false;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j]){
                isUpdated = true;
                answer.push_back(j-i);
                break;
            }
        }
        if(!isUpdated)
            answer.push_back(prices.size() - i -1);
    }
    return answer;
}