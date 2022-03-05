#include <string>
#include <vector>


using namespace std;

int solution(int n) {
    vector<int> v;
    int answer = 0;
    while(n!=0){
        v.push_back(n%3);
        n=n/3;
    }
    
    int multi = 1;
    while(!v.empty()){
        answer += multi*v.back();
        multi *= 3;
        v.pop_back();
    }
    return answer;
}