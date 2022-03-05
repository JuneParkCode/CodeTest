#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;


int breaker = 0;
// N = factor + R
void dp(int count, int now)
int solution(int n, int number){
    N=n;
    if(N==number) return 1;
    vector<vector<int>> Ns;
    map<int,int> numberMap;
    // N, NN ,NNN ... , 1,11,111...
    for(int i=0;i<=8;i++){
        Ns.push_back({});
    }
    for(int i=1,val=1; i<=8; i++){
        Ns[i].push_back(val*N);
        Ns[i+1].push_back(val);
        numberMap[val] = i+1;
        numberMap[val*N] = i;
        val = val*10 + 1;
    }
    numberMap[N] = 1;
    numberMap[0] = 2;
    Ns[1].push_back(N);
    if(numberMap[number] != 0) return numberMap[number];
    for(int i=2; i<=8; i++){
        for(auto x : Ns[i-1]){
            for(int k=1; k<=i-1;k++)
            {
                for(auto y :Ns[k]){
                    breaker ++;
                    if(x==0 || y==0) continue;
                    //cout << x <<" "<< y <<endl;
                    int v = k +i-1;
                    if(numberMap[x+y] > v || numberMap[x+y]== 0){
                        numberMap[x+y] = v;
                        Ns[v].push_back(x+y);
                        //if(number == x+y) return v;
                    }
                    if(numberMap[x-y] > v || numberMap[x-y]== 0){
                        numberMap[x-y] = v;
                        Ns[v].push_back(x-y);
                        //if(number == x-y) return v;
                    }
                    if(numberMap[x*y] > v || numberMap[x*y]== 0){
                        numberMap[x*y] = v;
                        Ns[v].push_back(x*y);
                        //if(number == x*y) return v;
                    }
                    if(numberMap[x/y] > v || numberMap[x/y]== 0){
                        numberMap[x/y] = v;
                        Ns[v].push_back(x/y);
                        //if(number == x/y) return v;
                    }
                    if(numberMap[y/x] > v || numberMap[x/y]== 0){
                        numberMap[y/x] = v;
                        Ns[v].push_back(y/x);
                        //if(number == x/y) return v;
                    }
                }
            }
        }
    }
    int ans = numberMap[number] < numberMap[-number] ? numberMap[number] : numberMap[-number];
    return ans >8 ? -1: ans;
}
int main(){
    cout << solution (5,4) << " " <<breaker;
}