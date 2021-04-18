#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

// 해결 못함...

long long minCount = INT64_MAX;
int Z;
using namespace std;
typedef pair<int,int> road;
struct city{
    set<road> goCityMap;
    city(road r){
        goCityMap.insert(r);
    }
    void addRoad(road r){
        goCityMap.insert(r);
    }
};
void move(int myCity,long long target,long long weight,int rw,long long count, map<int,city*> &cityMap){
    weight = rw + weight;
    if(target==weight){
        minCount = minCount > count ? count :minCount;
        return;
    }
    else if(target<weight)
        return;
    else if(count > minCount)
        return;
        
    city *curCity = cityMap[myCity];
    for(auto cit : curCity->goCityMap){
        int nextCity = cit.first;
        int w= cit.second;
        if(rw==0 && w ==0 && count!=0) continue;
        move(nextCity,target,weight,w,count+1,cityMap);
    }
}

vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    vector<long long> answer;
    map<int,city*> cityMap;
    int myCity = 0;
    Z=z;

    // 도시 생성
    for(int i=0; i<n; i++){
        cityMap[i] = new city(make_pair(i,Z));
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            road r = make_pair(j,0);
            cityMap[i]->addRoad(r);
        }
    }
    cout << "TEST"<<endl;
    // 도시 객체에 도로 연결
    for(auto r : roads){
        int u = r[0];
        int v = r[1];
        int w = r[2];
        road ro = make_pair(v,w);
        cityMap[u]->addRoad(ro);
        auto it = cityMap[u]->goCityMap.find(make_pair(v,0));
        if(it!=cityMap[u]->goCityMap.end())
            cityMap[u]->goCityMap.erase(it);
    }
    /*
    for(auto c : cityMap){
        city* cit = c.second;
        for(auto r : cit-> goCityMap){
            cout << r.first << " " << r.second <<endl;
        }
    }
    */

    for(auto i : queries){
        minCount = INT64_MAX;
        long long q1;
        q1 = i/Z * Z;
        q1 = q1 >= Z ? q1-Z : q1;
        move(myCity,i,q1,0,q1/Z,cityMap);
        answer.push_back(minCount==INT64_MAX ? -1 : minCount);
    }
    
    return answer;
}
int main(){
    int n = 3100;
    int z = 5;
    vector<vector<int>> roads  = {{1, 2, 3}, {0, 3, 2}};
    vector<long long> q = {0, 1, 2, 3, 4, 5,6,7,8,9,10,19381481};
    vector<long long> answer = solution(n,z,roads,q);
    for(auto c : q){
        cout << c <<" ";
    }
    cout << endl;
    for(auto c: answer){
        cout << c << " ";
    }
}