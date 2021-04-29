#include <iostream>
#include <string>
using namespace std;

// num을 N진법으로 나타냈을 때 string으로 반환.
string convert(int num){
    if(num >= 10){
        char res = num - 10 + 'A';
        string s;
        s += res;
        return s;   
    else{
        return to_string(num);
    }
}
string Ns(int N, int num){
    string s = "";
    while(num>=N){
        s = convert(num%N) + s;
        num /= N;
    }
    s = convert(num) + s;
    return s;
}

/* 
-------------------------------------------
   n ..........진법 
   m ..........참가인원
   p ..........튜브의 순서
   t ..........미리 구할 숫자의 갯수
-------------------------------------------
*/
string solution(int n, int t, int m, int p){
    
    string s= "";
    int i=0,j=0;
    while(i<t*m){
        string newS = Ns(n,j++);
        i += newS.length();
        s += newS;
    } // s에는 t바퀴 돌 만큼의 숫자 배열이 저장됨.
    
    // 결과 출력
    string ans ="";
    for(int k=0; k<t; k++){
        int idx = k*m + p -1;
        ans = ans + s[idx];
    }
    return ans;
}



//FOR TEST
int main(){

}