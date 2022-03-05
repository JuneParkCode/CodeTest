#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

// *** 해당 코드는 교차점에 대해서 처리를 하지 못함 **** //

//공간은 어떻게 형성되는가? --> 지나간 자리로 다시 돌아올 때 형성된다.
//다시 돌아올 때 ++를 하면 됨...
//예외 케이스 -> 이이전의 자리로 다시 돌아오는 경우 --> 해당 경우에는 ++를 하지 않는다.

// 움직일 때마다 객체가 생성되는 것으로 표현하는게 더 낫다고 생각함
// position 객체를 만들고 해당 객체가 가지고 있는 x,y좌표를 가상에 형성하자.
// 객체의 구성 --> int x,y; int vistedCount;
// 객체의 위치를 저장하는 2차원 테이블도 하나 만들면 좋을 것 같음 --> 중복 map 형태로 구성하자.

/*      Arrow
*       7 0 1   (-1,1)  (0,1)   (1,1)
*       6   2   (-1,0)          (1,0)
*       5 4 3   (-1,-1) (0,-1)  (1,-1)
*/


const int ARROW[8][2] {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,-1}};
struct position{
    int posX;
    int posY;
    bool isVisited[8] {0,0,0,0,0,0,0,0};
    position(int x,int y){
        posX=x;
        posY=y;
    }
    position(int x,int y,int arrow){
        posX=x;
        posY=y;
        checkFrom(arrow);
    }
    void checkFrom(int arrow){
        int dir = (arrow +4)%8;
        isVisited[dir] = 1;
    }
    void check2Go(int arrow){
        isVisited[arrow] = 1;
    }
    bool isVisitedRoad(int arrow){
        return isVisited[arrow];
    }
};
int solution(vector<int> arrows) {
    // position에 다시 닿을 때마다 공간 생성으로 인지.
    int answer = 0;                         
    // positionContainer[col][row] = position var 
    map<int,map<int,position*>> posMap; 
    vector<position *> forDelete;    
    // current Position , previous Postion, nextPosition
    position* curPos {new position(0,0)};
    position* prevPos =curPos;
    position* nextPos =curPos;
    posMap[0][0] = curPos;
    forDelete.push_back(curPos);
    // check if prev is New position?
    // a: 이동 방향
    for(auto a : arrows){
        // 현재 position의 좌표
        int x = ARROW[a][0] + curPos->posX;
        int y = ARROW[a][1] + curPos->posY;
        // 다음에 가는 포지션이 미개척지인가?
        if(posMap[x][y]!=NULL){
            // 이미 접근한 포지션에 다시 접근 
            nextPos = posMap[x][y];
            // 온 길이 왔던 길이 아니면 방이 생성됨
            if(!(curPos->isVisitedRoad(a)))
                ++answer;
        }
        else{
            //미개척 pos, 가는 방향 기록 후, 새로운 객체 생성 및 Map에 저장
            nextPos =  new position(x,y,a);
            posMap[x][y] = nextPos;
            forDelete.push_back(nextPos);
        }
        // 지나온 길 기록
        curPos->check2Go(a);
        nextPos->checkFrom(a);
        // 포지션 재할당.
        prevPos = curPos;
        curPos = nextPos;
    }
    for(auto i:forDelete)
        delete i;
    return answer;
}