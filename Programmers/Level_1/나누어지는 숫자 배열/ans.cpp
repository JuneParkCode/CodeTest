#include <string>
#include <vector>
#include <set>

using namespace std;
// my ans
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    set<int> sortedAns;
    for(auto n : arr)
        if(n%divisor==0)
            sortedAns.insert(n);
    for(auto n: sortedAns)
        answer.push_back(n);
    if(answer.size()==0)
        answer.push_back(-1);
    return answer;
}
// best ans
vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(int i =0; i <arr.size() ; i++){
        if(arr[i]%divisor==0) answer.push_back(arr[i]);
    }
    if(!answer.size()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
