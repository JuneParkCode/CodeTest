
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// my ans...
long long solution(int a, int b) {
    return (long long)(a+b) * double(abs(a-b)+1)/2;
}
// best ans
long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2; // 미친년 아니냐고....
    return answer;
}

