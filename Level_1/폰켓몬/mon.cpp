#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    set<int> monsterset;
    for(auto n: nums) monsterset.insert(n);
    return min(monsterset.size(),nums.size()/2);
}

int oldsol(vector<int> nums){
    int k=0,j = nums.size()/2;
    map<int,int> monsters;
    for(auto n : nums){
        monsters[n] += 1;
        if(monsters[n]==1)
            ++k;
    }
    if(j<=k)
        return j;
    else
        return k;
}