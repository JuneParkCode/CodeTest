#include <vector>
#include <iostream>
#include <set>
using namespace std;
typedef vector<int> subarr;                 // 원소 3개짜리 집합
// bool isPrime(int n){}                         // 소수인지 판별
// vector<subarr> tripleElements(vector<int> nums){}        // 부분집합 만들기
// int sum(subarr nums){}                           // 3자리 sum
vector<subarr> tripleElements(vector<int> &nums){
    vector<subarr> subArr;
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1;j++){
            for(int k=j+1; k<nums.size(); k++){
                cout << i << "," <<j<<","<<k<<endl;
                subArr.push_back({nums[i],nums[j],nums[k]});
            }
        }
    }
    return subArr;
}
bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int sum(subarr arr){
    int sum = 0;
    for(auto n:arr)
        sum += n;
    return sum;
}
int solution(vector<int> nums) {
    int answer = -1;
    set<int> sums;
    set<int> primes;
    vector<subarr> subArr {tripleElements(nums)};
    for(auto arr : subArr){
        sums.insert(sum(arr));
    }
    for(auto n : sums){
        if(isPrime(n)){
            primes.insert(n);
            cout << n <<" ";
        }
    }
    answer = primes.size();
    if(!answer)
        answer = -1;
    return answer;
}
int main(){
    vector<int> nums {1,2,3,4,5};
    cout << "answer : " << solution(nums);
}