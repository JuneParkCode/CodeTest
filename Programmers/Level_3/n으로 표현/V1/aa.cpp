#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
int target = 0;
int breaker =0;

// N = factor * q +- r
int solver(map<int,int> &factors, int number){
    if(breaker++ >= 100) return 0;
    int d = number;
    int q=0;
    int r=0;
    int count = 0;
    //cout << number <<endl;                          //Test
    if(number<=target) return factors[number];
    for(auto n: factors)   // factor/N으로 표현이 되는 경우
        if(number * target == n.first) return n.second + 1;
    for(auto n: factors){   // d * q + r  중 r 이 가장 작은 케이스를 찾아감.
        if(n.first>=0 && n.first<=target/2) continue;
        if(number == n.first)
            return factors[n.first];
        int mod = number % n.first;
        if(mod <= d){ // 몫에 가장 근접한 경우...
            d = n.first;
            q = number / n.first; 
            r = mod;
        }
        if(mod >= d)
            break;
    }
    // X = d q + r 
    // d * q 을 쉽게 풀어내는 방법이 있는가?
    // dq => factor / N 의 값인지도 체크해야함...
    //cout <<"D: "<<d <<" Q: "<< q << " R: "<< r << " +: "<<factors[d]<<endl; //Test
    if(q==1) // n = d + r
        return factors[d] + solver(factors,r);
    else
        return factors[d] + solver(factors,q) + solver(factors,r);
    /*
    if(q == 1) return factors[d]+ solver(factors,r);
    return r ? solver(factors,d*q) + solver(factors,r) : solver(factors,q) +solver(factors,r); + factors[d];
    */
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
        //cout <<val << " " << factors[val] <<endl;
        val++;
    }
    answer = solver(factors,number);
    int test = solver(factors,number*N) +1;
    //cout << answer << " " <<test <<endl;
    answer = answer > test ? test : answer;
    return answer > 8 ? -1 : answer;
}
int main(){
    cout << solution(1,1121);
}