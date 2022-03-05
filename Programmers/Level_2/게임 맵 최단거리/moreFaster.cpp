#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int dx[] ={1,0,0,-1};
const int dy[] ={0,-1,1,0}; // 우,하,상,좌
int N;
int M;

int ansMin = INT32_MAX;
// maps[y][x]
// start point = 1,1 (idx = 1 start)
// end point = n,m
struct position{
    int x;
    int y;
    int count;
    position(int x_,int y_,int count_){
        x=x_;
        y=y_;
        count=count_;
    }
};
bool isValidPosition(position curPos,vector<vector<int>> &maps){
    if(0<=curPos.x && curPos.x<M && 0<=curPos.y && curPos.y<N && maps[curPos.y][curPos.x])
        return 1;
    return 0;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<position> targetQ;
    N = maps.size();
    M = maps[0].size();
    targetQ.push(position(0,0,0));
    position curPos = targetQ.front();
    while(!targetQ.empty()){
        if(curPos.x==(M-1) && curPos.y==(N-1)) return curPos.count+1;
        targetQ.pop();
        for(int i=0;i<4;i++){
            int tx = curPos.x + dx[i];
            int ty = curPos.y + dy[i];
            position newPos(tx,ty,curPos.count+1);
            if(isValidPosition(newPos,maps)){
                if(newPos.count < maps[ty][tx] || maps[ty][tx] ==1 ){ // shortcut
                    maps[ty][tx] = newPos.count;
                    targetQ.push(newPos);
                }
            }
        }
        curPos = targetQ.front();
    }
    return targetQ.empty() ? -1 : curPos.count;
}
int main(){
    vector<vector<int>> maps ={{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    cout << solution(maps);
}