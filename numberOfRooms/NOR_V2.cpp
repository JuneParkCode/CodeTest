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