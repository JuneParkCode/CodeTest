#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int N;
int breaker = 0;
// N = factor + R
int solution(int n, int number){
    N=n;
    if(N==number) return 1;
    vector<set<int>> Ns;
    map<int,int> numberMap;
    // N, NN ,NNN ... , 1,11,111...
    for(int i=0;i<=20;i++){
        Ns.push_back({});
    }
    for(int i=1,val=1; i<=8; i++){
        Ns[i].insert(val*N);
        Ns[i+1].insert(val);
        numberMap[val] = i+1;
        numberMap[val*N] = i;
        val = val*10 + 1;
    }
    bool check = 0;
    int checker,temp=0;
    int min = INT32_MAX;
    numberMap[N] = 1;
    numberMap[0] = 2;
    Ns[1].insert(N);
    if(numberMap[number] != 0) return numberMap[number];
    for(int i=2; i<=8; i++){
        for(auto x : Ns[i-1]){
            for(int k=1; k<=i-1;k++)
            {
                for(auto y :Ns[k]){
                    if(x==0 || y==0) continue;
                    //cout << x <<" "<< y <<endl;
                    int v = k +i-1;
                    if(numberMap[x+y] > v || numberMap[x+y]== 0){
                        numberMap[x+y] = v;
                        Ns[v].insert(x+y);
                    }
                    if(numberMap[x-y] > v || numberMap[x-y]== 0){
                        numberMap[x-y] = v;
                        numberMap[y-x] = v;
                        Ns[v].insert(x-y);
                    }
                    if(numberMap[x*y] > v || numberMap[x*y]== 0){
                        numberMap[x*y] = v;
                        Ns[v].insert(x*y);
                    }
                    if(numberMap[x/y] > v || numberMap[x/y]== 0){
                        numberMap[x/y] = v;
                        Ns[v].insert(x/y);
                    }
                    int cur = numberMap[number];
                    if(temp <= cur){
                        if(checker) return cur;
                        temp = cur;
                        checker = true;
                    }
                }
            }
        }
    }
    int ans = numberMap[number] != 0 ? numberMap[number] : numberMap[-number];
    return ans >8 ? -1: ans;
}
int main(){
    cout << solution (5,4);
}