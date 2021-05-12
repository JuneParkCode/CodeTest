#include <string>
#include <vector>
#include <iostream>
#include <map>

#define SWAP(x,y,t) ((t=x),(x=y),(y=t))
using namespace std;
// 네오 (0) 프로도
// 라이언 (2) 프로도
// DATA : ["N~F=0", "R~T>2"]	가능한 경우의 수 3648
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

/*
1. 조건을 검증하는 함수가 필요함
2. 조건에 부합하는 경우의 수를 모두 계산.
*/
bool isValidMemberSet(vector<int> &members,const map<char,int> &idxMap,const vector<string> &data){
    for(string condition : data){
        // CONDITION A~B SIGN NUMBER
        int a = members[idxMap.at(condition[0])]; // 현재 위치
        int b = members[idxMap.at(condition[2])]; 
        char sign = condition[3];
        int number = condition[4] -'0';
        if(sign == '>'){
            if(abs(a-b) > (number+1)) continue;
        }
        else if(sign == '<'){
            if(abs(a-b) < (number+1)) continue;
        }
        else{ //sign == '='
            if(abs(a-b) == (number+1)) continue;
        }
        return 0;
    }
    return 1;
}

void doFactorialRecursion(int start,int end,int &answer,vector<int> &members,const map<char,int> &idxMap,vector<string> &data ){
    if(start==end){
        answer+= (isValidMemberSet(members,idxMap,data));
    }
    for(int i=start; i<end; i++){
        int temp;
        SWAP(members[start],members[i],temp);
        doFactorialRecursion(start+1,end,answer,members,idxMap,data);
        SWAP(members[start],members[i],temp);
    }
}
int solution(int n, vector<string> data) {
    int answer = 0;
    const char members[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> memberVec  {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<int> idxVec {0,1,2,3,4,5,6,7};
    vector<char> photo(8,0);
    map<char, int> idxMap;
    for(int i=0;i<8;i++){
        idxMap[members[i]]=i;
    }
    doFactorialRecursion(0,8,answer,idxVec,idxMap,data);
    //doFactorialRecursion(8,answer,memberVec,data);
    return answer;
}
int main(){
    cout<<solution(8,{"N~F=0", "R~T>2"});
}