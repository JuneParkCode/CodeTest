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
    /*
    if(breaker++ >= 100){
        cout << "BREAK" <<endl;
        return 0;
    }
    */
    cout << number<<endl;
    int e = target%2==0 ? target/2 : target/2 *1;
    if(number <= e || factors[number] !=0){
        return factors[number];
    }
    for(auto n: factors)   // factor/N으로 표현이 되는 경우
        if(number * target == n.first) return factors[number] ? factors[number] : n.second +1;
    // x = d + r
    int min = INT32_MAX;
    int d=0;
    int r=0;
    for(auto n: factors){
        if(n.first < target || n.second == 0) continue;
        if(n.first == number) return factors[number];
        int dif = abs(number - n.first);
        if(min > dif){
            min = dif;
            d = n.first;
            r = dif;
        }
        if(dif > min)
            break;
    }
    if(d==target) return factors[r]+1;
    cout << "D: " << d << " R: "<< r<<" "<< factors[d]<<endl;
    int a,b;
    if(number % target == 0)
        return (a=solver(factors,r) + factors[d]) <(b=number/target) ? a:b ;
    else
        return (solver(factors,r) + factors[d]);
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
    while (val<=32000 && N!=1){ 
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
    count = 2;
    while(++count < number){
        if(count%N!=0) continue;
        factors[count] = solver(factors,count);
        cout << count << " "<< factors[count] <<endl;
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