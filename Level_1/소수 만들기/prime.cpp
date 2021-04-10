#include <vector>
using namespace std;  
//  소수인지 판별
bool isPrime(int n){
    for(int i=2; i<n; i++)
        if(n%i==0)
            return false;
    return true;
}
int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0; i<nums.size()-2; i++)
        for(int j=i+1; j<nums.size()-1;j++)
            for(int k=j+1; k<nums.size(); k++)
                answer += isPrime(nums[i]+nums[j]+nums[k]); 
    return answer;
}