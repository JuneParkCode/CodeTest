#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> position;

vector<position> KEY= {
    {1,3},
    {0,0},{1,0},{2,0},
    {0,1},{1,1},{2,1},
    {0,2},{1,2},{2,2}
};
int distance(int n, position t){
    position N = KEY[n];
    return abs(N.first-t.first)  + abs(N.second-t.second);
}
string f(int n, position &lH, position &rH,bool isRightHand){
    if(n==1 ||n==4||n==7){ // left
        lH = KEY[n];
        return "L";
    }
    else if (n==3||n==6||n==9){ // right
        rH = KEY[n];
        return "R";
    } 
    else{
        if(distance(n,lH) == distance(n,rH)){
            if(isRightHand){
                rH=KEY[n];
                return "R";
            }
            else{
                lH=KEY[n];
                return "L";
            }
        }
        else{
            if(distance(n,lH) > distance(n,rH)){
                rH = KEY[n];
                return "R";
            }
            else{
                lH = KEY[n];
                return "L";
            }
        }
    }
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    bool isRightHand = hand=="right" ? 1:0;
    position lH = {0,3};
    position rH = {2,3};
    for(auto n : numbers)
        answer += f(n,lH,rH,isRightHand);
    return answer;
}