#include <vector>
#include <set>
#include <iostream>
using namespace std;
// 모서리 - 꼭짓점  = 공간의 개수
// 꼭짓점 --> 어떤 기준으로 형성? new [x][y] -->  이어지는 경우에는 성립할 수 없음...
// 모서리 --> 어떤 기준으로 형성? edge --> start point  - end point 
typedef pair<int,int> position;
int solution(vector<int> arrows){
    const int ARROW[8][2] {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    auto vertex {set<position>()};
    auto edge {set<pair<position,position>>()}; //  (start , end) type : position
    int x=0,y=0;
    position curPos {make_pair(x,y)};
    position nextPos {curPos};
    vertex.insert(curPos);
    for(const auto a: arrows){
        for(int i=0; i<2 ; i++){    // 두번 진행함으로써 가운데 점에 대해서도 생성함!!!
            int nx = x+ARROW[a][0],ny = y+ARROW[a][1]; // next position
            curPos = make_pair(x,y);
            nextPos = make_pair(nx,ny);
            vertex.insert(nextPos);
            position start,end;
            if(curPos > nextPos)    // 모서리 s,e 결정
                start = nextPos, end = curPos;
            else
                start = curPos, end = nextPos;
            edge.insert(make_pair(start,end));
            x=nx,y=ny;
        }
    }
    int answer = 1 - vertex.size() + edge.size();
    return answer;
}
