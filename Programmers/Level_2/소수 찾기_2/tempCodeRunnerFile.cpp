#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

const int C = '0';

using namespace std;
bool isPrime(int n){
    if(n<=1) return 0;
    for(int i=2; i*i<=n; i++)
        if(n % i ==0 ) return 0;
    return 1;
}
vector<int> splitString(string s,set<int> &sums){
    vector<int> numbers;
    for(char n : s){
        numbers.push_back(n-C);
        sums.insert(n-C);
    }
    return numbers;
}
int sum(set<int> &sums,vector<int> numbers,int ten,int i,int len){
    if(i>=len)
        return 0;
    int result = 0;
    auto it = numbers.begin();
    for(int k=0; k<numbers.size(); k++){
        int n = *it;
        it = numbers.erase(it);
        int prevRes = sum(sums,numbers,ten/10,i+1,len);
        result = n*ten + prevRes;
        numbers.push_back(n);
        sums.insert(result);
    }
    return result;
}
int solution(string s) {
    int answer = 0;
    set<int> sums;
    vector<int> numbers=splitString(s,sums);
    sum(sums,numbers,pow(10,numbers.size()-1),0,numbers.size());
    for(auto n : sums){
        cout << n <<endl;
        answer += isPrime(n);
    }
    return answer;
}
int main(){
    cout << solution("01234985");
}