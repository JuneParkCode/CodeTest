#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int N;
int breaker = 0;
map<int,int> NNs;
// N = factor + R
int solver(int n,bool Q= false){
    //if(++breaker > 10) return 0;
    if(n==0) return n;
    else if(Q) return n==1?1:solver(n);
    int ans;
    int aIdx,aQ,aR;
    int min = INT32_MAX;
    int cMin = INT32_MAX;
    int q = 0;
    int r = 0;
    int idx = 0;
    int SD,SR,SQ;
    if(NNs[n]!=0) return NNs[n];
    if(n/N <= 4 && n%N ==0) return n/N;
    for(auto i : NNs){
        if(i.second == 0 || i.first <=1) continue;
        int dif = abs(i.first-n);
        if(min >= dif) min = dif;
        else break;
        if(i.first== n) return NNs[n];
        idx = i.first;
        q = idx > n ? 1 : n/idx;
        min = dif;
        r = idx > n ? idx - n : n%idx;
        int a = (SD=NNs[idx]) * (SQ=solver(q,1)) +(SR=solver(r));
        int b = SD * q +SR;
        
        int ps = a<b? a:b;

        cout << n << " D " <<idx << " Q " << q << " R " << r ;
        cout<<"PS: "<<ps<<endl;
        if(cMin>ps){
            cMin = ps;
            aIdx = idx;
            aQ = q;
            aR = r;
            ans = ps;
        }
    }
    if(N==1) return ans;
    
    q = n<=N ? 1 : n/N;
    r = n<=N ? N-n : n%N;
    cout << N << " Q " << q << " R "<< r <<endl;
    int c = 1 +  (SQ=solver(q,1)) +(SR=solver(r));
    int d = SD * q + SR;
    c= c<d?c:d;

    if(cMin > c)ans = c;
    cout << n << " ANS: "<<ans<<endl;

    return ans;
}

int solution(int n, int number){
    N = n;
    int e = N%2==0?N/2:N/2+1;
    
    // 1,11,111... 의 배수인가?
    NNs[0] = 0;
    NNs[N] = 1;
    
    for(int i=2; i<=e; i++)
        NNs[i] = i;
    for(int i=1,count=1; i<=number*10;count++){
        NNs[i] = count+1 ; 
        NNs[i*N] = count;
        i = i*10 +1;
    }
    for(auto c :NNs)
        cout << c.first <<" "<<c.second <<endl;
    int a = solver(number);
    int b = solver(number*N) +1;
    int ans = a<b?a:b;
    return ans> 8 ? -1 : ans;
}
int main(){
    cout << solution (4,17);
}