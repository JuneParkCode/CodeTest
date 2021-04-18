#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

// 해결 못함...

long long minCount = INT64_MAX;
int Z;
int N;
using namespace std;
typedef map<int,int> road;
set<int> haveRoadCities;
map<int,long long> weights;
struct city{
    road goCityMap;
    city(int e, int w){
        goCityMap[e] = w;
    }
    void addRoad(int e, int w){
        goCityMap[e] = w;
    }
};
void move(int myCity,long long target,long long weight,int rw,long long count, map<int,city*> &cityMap){
    weight = rw + weight;
    if(target==weight){
        minCount = minCount > count ? count :minCount;
        weights[weight] = count;
        return;
    }
    else if(target<weight ||count > minCount)
        return;
    if(weights[weight] >= count || weights[weight]){
        weights[weight] = count;  
    }
    else if(weights[weight] < count && weights[weight] != 0 && rw!=0)
        return;
        
    city *curCity = cityMap[myCity];
    // my city에서 연결된 장소로 move
    for(auto m : curCity->goCityMap){
        int nextCity = m.first;
        int w = m.second;
        if(rw==0 && w ==0 && count!=0) continue;
        //cout << myCity <<" --> " << nextCity << " " << w <<endl;
        move(nextCity,target,weight,w,count+1,cityMap);
    }
    if(myCity==-1) return;
    // 순간이동의 경우 --> 길이 있는 도시로만...
    for(auto nextCity : haveRoadCities){
        int w = curCity->goCityMap[nextCity];
        if(rw==0 && w ==0 && count!=0) continue;
        //cout << myCity <<" --> " << nextCity << " " << w <<endl;
        move(nextCity,target,weight,w,count+1,cityMap);
    }
}

vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    vector<long long> answer;
    map<int,city*> cityMap;
    set<int> targetCities;
    cityMap[-1] = new city(-1,0);
    cityMap[-1]->addRoad(0,1);

    int myCity = 0;
    Z=z,N=n;
    for(int i=0; i<n; i++){
        cityMap[i] = new city(i,Z);
    }
    // 도시 생성

    
    // 도시 객체에 도로 연결
    for(auto r : roads){
        int u = r[0];
        int v = r[1];
        int w = r[2];
        cityMap[u]->addRoad(v,w);
        haveRoadCities.insert(u);
    }
    /*
    //ROAD INPUT TEST
    for(auto c : cityMap){
        city* cit = c.second;
        for(auto r : cit-> goCityMap){
            cout << r.first << " " << r.second <<endl;
        }
    }
    for(auto c : haveRoadCities){
        cout << c <<endl;
    }
    */
    

    for(auto i : queries){
        minCount = INT64_MAX;
        move(-1,i,0,0,-1,cityMap);
        answer.push_back(minCount==INT64_MAX ? -1 : minCount);
        //cout << i<<endl;
    }
    
    return answer;
}
int main(){
    int n = 5;
    int z = 49;
    vector<vector<int>> roads  = {{1, 2, 3}, {0, 3, 2}};
    vector<long long> q = {0, 1, 2, 3, 4, 5,6,7,8,9,10,2102};
    vector<long long> answer = solution(n,z,roads,q);
    for(auto c : q){
        cout << c <<" ";
    }
    cout << endl;
    for(auto c: answer){
        cout << c << " ";
    }
}