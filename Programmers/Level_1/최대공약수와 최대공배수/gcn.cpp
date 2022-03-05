#include <string>
#include <vector>

using namespace std;


// 이런 형식의 재커 함수도 가능함...
int u(int a, int b){
    return b ? u(b,a%b) : a;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int min = n <= m ? n : m;
    int max = n > m ? n : m;

    int a=max,b=min;
    while(a%b != 0){
       int temp = b;
       b=a%b;
       a=temp;
    } 
        
    int gcm = b;
    int lcm = a/gcm  * b/gcm;
    return answer = {gcm,lcm};
}