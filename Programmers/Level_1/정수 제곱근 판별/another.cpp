#include <string>
#include <vector>
#include <cmath>

using namespace std;
//my sol..
// 이게 더빠름
long long solution(long long n){
    long long sq = sqrt(n);
    return (sq*sq) == n ? (sq+1)*(sq+1) : -1; 
}

// sol2
// function을 따로 가져오지 않고 풀 수 있는 거...
long long solution(long long n) {
    long long i;
    for(i=1; i*i <= n; i++);
    
    return ((i-1)*(i-1) == n)  ? (i)*(i) : -1;
}