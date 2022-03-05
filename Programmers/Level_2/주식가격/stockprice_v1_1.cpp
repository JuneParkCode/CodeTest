#include <string>
#include <vector>

/*
테스트 1 〉	통과 (27.39ms, 24.3MB)
테스트 2 〉	통과 (18.24ms, 18.9MB)
테스트 3 〉	통과 (28.71ms, 26.8MB)
테스트 4 〉	통과 (21.25ms, 21.4MB)
테스트 5 〉	통과 (14.92ms, 16.2MB)
별차이 없는듯.
*/
using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    // 가장 간단한 방법...
    for(int i=0; i<prices.size(); i++){
        bool isUpdated =false;
        for(int j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j]){
                isUpdated = true;
                answer[i]=(j-i);
                break;
            }
        }
        if(!isUpdated){
            answer[i]= (prices.size() - i -1);
        }
    }
    return answer;
}