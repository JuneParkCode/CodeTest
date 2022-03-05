#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
}

// vertex -> 구분할 수 있는 번호
struct vertex
{
    int name;
};
// edge -> cost, 연결된 지점을 가지고 있어야한다.
struct edge
{
    pair<vertex,vertex> nodes;
    int cost;
};

// 각 노드는 타 노드로 향하는 비용을 저장한다.
struct node
{
    vertex point; 
    vector<int> costs;
};


int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    return answer;
}