#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
int target = 0;
int breaker =0;

// N = factor * q +- r
int solver(map<int,int> &factors, int number,bool dq=false){
    if(breaker++ >= 1000){
        cout << "BREAK" <<endl;
        return 0;
    }
    if(dq) number = target * number;
    int d = number;
    int min = 32000;
    int q=0;
    int r=0;
    int count = 0;
    //cout << number <<endl;                          //Test
    if(number<=target)  return factors[number];
    for(auto n: factors)   // factor/N으로 표현이 되는 경우
        if(number * target == n.first) return factors[number] ? factors[number] : n.second +1;
    for(auto n: factors){   // d * q + r
        if(n.first>=0 && n.first<=target/2) continue;
        if(number == n.first)
            return factors[n.first];
        int mod = number % n.first;
        int dif = abs(number - n.first);
        if(min>dif){ // 가장 값과 가까운 거
            min = dif;
            d = n.first;
            q = number < n.first ? 1 : number / n.first; 
            r = number < n.first ? number - n.first : number / n.first;
            r = abs(r);
        }
        if(dif > min)
            break;
    }
    // X = d q + r 
    // d * q 을 쉽게 풀어내는 방법이 있는가?
    // dq => factor / N 의 값인지도 체크해야함...
    int a,b;
    cout <<"N: "<<number<<" D: "<<d <<" Q: "<< q << " R: "<< r << " +: "<<factors[d]<<endl; //Test
    if(q==1) // n = d + r
        return factors[d] + solver(factors,r);
    else
        return (a=solver(factors,q,false)) < (b=solver(factors,q,!dq)) ? a + solver(factors,r) : b+ solver(factors,r);
}
int solution(int N, int number) {
    int answer = 0;
    map<int,int> factors; // 값, n의 개수
    // N = factors * q  +- r ( 0<=r<=n/2)
    // q = factors * k +- r
    int val = N; 
    int count = 1;
    target = N;
    // N으로만 구성되는 수에 대해서
    while(val <= 32000){    
        factors[val] = count++;
        val = val * 10 + N;
    }
    val = N;
    count=1;
    // N의 곱으로 표현할 수 있는 수...
    while (val<=32000){ 
        factors[val] = count++;
        val *= N;
    }
    // Factors의 곱으로만 표현할 수 있는 수
    for(auto n: factors){
        for(auto m: factors){
            if(n.first == 0 || m.first == 0) continue;
            int multiply = n.first * m.first;
            if(multiply>32000) break;
            int var = factors[n.first] + factors[m.first];
            if(factors[multiply] != 0)
                var = factors[multiply] > var ? var:factors[multiply];
            factors[multiply] = var;    
        }
    }
    // Factors의 나눗셈으로 표현할 수 있는 수
    for(auto n: factors){
        for(auto m: factors){
            if(m.first==0 || n.first==0) continue;
            int multiply = n.first / m.first;
            if(n.first % m.first != 0) break;
            int var = factors[n.first] + factors[m.first];
            if(factors[multiply] != 0)
                var = factors[multiply] > var ? var:factors[multiply];
            factors[multiply] = var; 
        }
    }
    // 0<= r <= N/2 에 대해서 표현
    val = 2;
    int e = N&1?(N/2)+1:N/2;
    while(val <=e){ 
        if(val == 4)
            factors[4] = factors[2]*2 < val +1 ? factors[2]*2 : val +1;
        else
            factors[val] = val + 1;
        val++;
    }

    int a = solver(factors,number);
    int test = solver(factors,number*N)+1; 
    answer = a<test?a:test;
    return answer = answer > 8 ? -1 : answer;
}
int main(){
    cout << solution(1,1121) <<endl;
}


// for test
//cout <<"N: "<<number<<" D: "<<d <<" Q: "<< q << " R: "<< r << " +: "<<factors[d]<<endl; //Test
/* factor check
for(auto n: factors)
    cout << n.first <<" " <<n.second <<endl;
*/