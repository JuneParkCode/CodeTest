#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
/*                  Arrow
*
*       7 0 1   (-1,1)  (0,1)   (1,1)
*       6   2   (-1,0)          (1,0)
*       5 4 3   (-1,-1) (0,-1)  (1,-1)
*
*/
// 교차 = 공간의 형성?
// 대각선 교차 --> newPos여도 공간 형성 ,old pos일 경우 온 방향에 대해서 각각 공간이 하나씩 만들어짐
// 일반 교차 --> oldPos에 대해서만 공간 형성.
const int ARROW[8][2] {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
struct position{
    int posX;
    int posY;
    bool isVisited[8] {0,0,0,0,0,0,0,0};
    bool crossed[4] {0,0,0,0}; // 각각 1,3,5,7 방향에 대해서...
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
        isVisited[dir] = true;
    }
    void check2Go(int arrow){
        isVisited[arrow] = true;
    }
    bool isVisitedRoad(int arrow){
        return isVisited[arrow];
    }
    void itsCross(int arrow){
        int i = (arrow - 1)/2;
        crossed[i] = true;
    }
    bool isCrossed(int arrow){
        int i = (arrow -1)/2;
        return crossed[i];
    }
};
bool crosscheck(position &curPos,position &nextPos,position &xtargetPos,position &ytargetPos,int arrow){
    // 대각선인 경우에 대해서 크로스 체크
    // tArrow = 교차될 수 있는 방향의 arrow..
    int tArrow=0;
    if(arrow == 1)//1,1
        tArrow = 7;
    else if(arrow == 3)//1,-1
        tArrow = 5;
    else if(arrow == 5)//-1,-1
        tArrow = 3;
    else if(arrow == 7)//-1,1
        tArrow = 1;
    else{
       
        return false;
    }
    if(xtargetPos.isVisitedRoad(tArrow)){
        if(curPos.isCrossed(arrow)){
            return false;
        }
        else{
            curPos.itsCross(arrow);
            nextPos.itsCross((arrow+4)%8);
            xtargetPos.itsCross(tArrow);
            ytargetPos.itsCross((tArrow+4)%8);
            return true;
        }
    }
    return false;
}
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
        // Check it is crossed
        int tX=curPos->posX;
        int tY=curPos->posY;
        position *xtargetPos = posMap[tX+ARROW[a][0]][tY];
        position *ytargetPos = posMap[tX][tY+ARROW[a][1]];
        if(xtargetPos != nullptr && ytargetPos != nullptr)
            answer += crosscheck(*curPos,*nextPos,*xtargetPos,*ytargetPos,a);
        // 지나온 길 기록
        curPos->check2Go(a);
        nextPos->checkFrom(a);
        // 포지션 재할당
        prevPos = curPos;
        curPos = nextPos;
    }
    for(auto i:forDelete)
        delete i;
    return answer;
}
int main(){
    vector<int> arrows{5,2,7,1,6,3};
    cout << solution(arrows);
}