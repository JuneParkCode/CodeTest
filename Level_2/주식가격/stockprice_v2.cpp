#include <string>
#include <vector>
#include <stack>

using namespace std;
/*
테스트 1 〉	통과 (25.57ms, 24.3MB)
테스트 2 〉	통과 (17.65ms, 18.8MB)
테스트 3 〉	통과 (29.51ms, 26.9MB)
테스트 4 〉	통과 (20.97ms, 21.3MB)
테스트 5 〉	통과 (15.53ms, 16.2MB)
로직이 유사해서 속도 차이가 나지 않음...
*/


vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<pair<int,int>> st;    // price / idx , 그냥 <int> 로 하고 prices를 통해서 접근하는게 나음.
    int cur=prices[0];
    for(int i=0;i<prices.size();i++){
        cur = prices[i];
        // 하락이 체크되었을 때
        while(!st.empty()&&st.top().first>cur){
            answer[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push(make_pair(cur,i));
    }
    while(!st.empty()){
        answer[st.top().second] = prices.size() - st.top().second -1;
        st.pop();
    }

    return answer;
}