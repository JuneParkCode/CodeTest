#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;
long long lcount = 0;
long long MinCount = INT64_MAX;
struct node{
    set<node*> children;
    int content;
    node(int c){
        content = c;
    }
    void addChild(node* p){
        children.insert(p);
    }
};

long long fsum(node* myNode,node* parentNode=nullptr){
    long long res = 0;
    for(auto nod : myNode->children){
        if(nod == parentNode) continue;
        long long s = fsum(nod,myNode);
        res += s;
    }
    lcount += abs(res + myNode->content);
    return res + myNode->content;
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    bool test = 0;
    // node 생성
    map<int,node*> nodeMap;
    for(int i=0; i<a.size(); i++){
        int n = a[i];
        node* newNode = new node(n);
        nodeMap[i] = newNode;
        if(a[i]!=0) test = 1;
    }
    if(!test) return 0;
    // node 별로 연결...
    for(auto e :edges){
        nodeMap[e[0]]->addChild(nodeMap[e[1]]);
        nodeMap[e[1]]->addChild(nodeMap[e[0]]);
    }
    // 가중치 --> 연결된 트리에 넘겨주려면 가중치만큼 건내줘야함.
    // child의 가중치 합을 계속 조사해 나가면 됨..
    for(auto n : nodeMap){
        node* myNode = n.second;
        lcount = 0;
        long long res = fsum(myNode);
        if(res==0 && lcount > 0) MinCount = lcount < MinCount ? lcount :MinCount;
        break;
    }
    return MinCount == INT64_MAX ?  -1 : MinCount;
}