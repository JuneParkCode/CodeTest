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
set<pair<int,int>> weightMap;       // w / e
struct city{
    road goCityMap;
    city(int e, int w){
        goCityMap[e] = w;
    }
    void addRoad(int e, int w){
        goCityMap[e] = w;
    }
};
void move(int i,int count,int myCity){
    // i = wq  + r
    for(auto o: weightMap){
        
    }
}

vector<long long> solution(int n, int z, vector<vector<int>> roads, vector<long long> queries) {
    vector<long long> answer;
    map<int,city*> cityMap;
    set<int> targetCities;


    int myCity = 0;
    Z=z,N=n;
    for(int i=0; i<n; i++){
        cityMap[i] = new city(i,Z);
    }
    // 도시 객체에 도로 연결
    for(auto r : roads){
        int u = r[0];
        int v = r[1];
        int w = r[2];
        cityMap[u]->addRoad(v,w);
        weightMap.insert(make_pair(w,v));
    }
    for(int i=0; i<2*Z; i++){
        move(i);
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
        move(i);
        answer.push_back(minCount==INT64_MAX ? -1 : minCount);
        //cout << i<<endl;
    }
    
    return answer;
}
int main(){
    int n = 5;
    int z = 5;
    vector<vector<int>> roads  = {{1, 2, 3}, {0, 3, 2}};
    vector<long long> q = {0, 1, 2, 3, 4, 5,6,7,8,9,10,20};
    vector<long long> answer = solution(n,z,roads,q);
    for(auto c : q){
        cout << c <<" ";
    }
    cout << endl;
    for(auto c: answer){
        cout << c << " ";
    }
}