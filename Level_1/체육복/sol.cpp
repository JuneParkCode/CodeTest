#include <string>
#include <vector>
#include <map>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) { // 아 너무 어렵다....
    map<int,bool> lostMap;
    map<int,bool> reserveMap;
    for(auto i: lost){
        lostMap[i] = 1;
        --n;
    }
    for(auto i: reserve){
        if(lostMap[i]){lostMap[i]=0;++n;}
        else
            reserveMap[i] = 1;
    }
    
    for(auto i: reserve){
        if(!reserveMap[i])
            continue;
        if(lostMap[i-1]){
            ++n;
            lostMap[i-1] =0;
            continue;
        }
        if(lostMap[i+1]){
            ++n;
            lostMap[i+1] = 0;
        }
    }
    
    return n;
}