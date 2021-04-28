#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] ={1,0,0,-1};
const int dy[] ={0,-1,1,0}; // 우,하,상,좌
int N;
int M;

int ansMin = INT32_MAX;
// maps[y][x]
// start point = 1,1 (idx = 1 start)
// end point = n,m
int move(int x,int y,int i,vector<vector<int>> &maps){
    // 0<=x<m and 0<=y<n , is shorcut? 
    if(x>=0 && x<M && y>=0 && y <N && (maps[y][x] > i || maps[y][x]==1) && (M-x + N-y + i) <ansMin){
        // 최단거리 기록.
        maps[y][x]=i; 
        //ARRIVED
        if(x==(M-1) && y==(N-1))
            return i+1;
        for(int j=0; j<4; j++){
            int tx = dx[j] + x;
            int ty = dy[j] + y;
            // 0<=x<m and 0<=y<n , is shorcut? 
            if(tx>=0 && tx<M && ty>=0 && ty <N &&  (maps[ty][tx] > i || maps[ty][tx]==1)){
                int check = move(tx,ty,i+1,maps);
                ansMin = (ansMin>check && check!=-1)? check : ansMin;
            }
        }
        return ansMin==INT32_MAX? -1:ansMin;
    }
    // over/under index or not shortCut
    return -1;
}
int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();
    int answer = move(0,0,0,maps);
    return answer;
}
int main(){
    vector<vector<int>> maps ={{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    cout << solution(maps);
}