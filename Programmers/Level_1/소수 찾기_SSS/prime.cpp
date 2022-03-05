#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(int n,vector<int> &primes){
    double sq = sqrt(n);
    for(auto pn : primes){
        if(n%pn==0) return 0;
        if(pn > sq) break;
    }
    primes.push_back(n);
    return 1;
}
// 홀수에 대해서만?
int solution(int n) {
    int answer = 0;
    vector<int> primes;
    for(int i=2; i<=n; i++)
        answer += isPrime(i,primes);
    return answer;
}