#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers){
    vector<int> answer;
    set<int> sortAns;   // 중복 무시, 정렬이므로 set이 합리적이다.
    int end = numbers.size();
    for(int i=0;i<end-1; i++){
        for(int j=i+1; j<end; j++){
            sortAns.insert(numbers[i]+numbers[j]); 
        }
    }
    for(auto n: sortAns){
        answer.push_back(n);
    }
    return answer;
}