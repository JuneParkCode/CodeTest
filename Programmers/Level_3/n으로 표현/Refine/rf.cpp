#include <string>
#include <vector>
#include <iostream>
using namespace std;

int minCnt = 9;
int N,NUM;
void dp(int cnt, int now){
    if(cnt>8) return;
    if(NUM == now)
        minCnt = minCnt < cnt ? minCnt :cnt;
    int temp = 0;
    for(int i=1; i<=8; i++){
        temp = temp *10 + N;
        dp(cnt+i,now+temp);
        dp(cnt+i,now-temp);
        if(now!=0){
            dp(cnt+i,now*temp);
            dp(cnt+i,now/temp);
        }
    }
}
int solution(int N_, int number) {
    int answer = 0;
    N=N_;
    NUM=number;
    dp(0, 0);
    answer = ((minCnt > 8) ? -1 : minCnt);
    return answer;
}
int main(){
    cout << solution(1,1121);
}