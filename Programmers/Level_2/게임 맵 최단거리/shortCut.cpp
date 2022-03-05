#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] ={1,0,0,-1};
const int dy[] ={0,-1,1,0}; // 우,하,상,좌

int ansMin = INT32_MAX;
// maps[y][x]
// start point = 1,1 (idx = 1 start)
// end point = n,m
int move(int x,int y,int px,int py,int i,vector<vector<int>> &maps,vector<vector<bool>> &search){
    // 0<=x<m and 0<=y<n , not searched, not wall
    const int N = maps.size();
    const int M = maps[0].size();
    if(x>=0 && x<M && y>=0 && y <N && maps[y][x] && !search[y][x]){
        search[y][x]=true; // ITS SEARCHED AREA!
        if(x==(maps[0].size()-1) && y==(maps.size()-1)){
            return i+1;
        }
        // 단축을 위함
        if( ((M-x) + (N-y) + i) >= ansMin) return -1;
        for(int j=0; j<4; j++){
            int tx = dx[j] + x;
            int ty = dy[j] + y;
            if(tx>=0 && tx<M && ty>=0 && ty <N && maps[ty][tx] && !search[ty][tx]){
                int check = move(tx,ty,x,y,i+1,maps,search);
                if(check!=-1){
                    ansMin = ansMin>check? check : ansMin;
                }
                search[ty][tx] = 0;
            }
        }
        // 단축용
        return ansMin==INT32_MAX? -1:ansMin;
    }
    // over/under index or wall , searched
    return -1;
}
int solution(vector<vector<int> > maps)
{
    vector<bool> t(maps[0].size(),0);
    vector<vector<bool>> search(maps.size(),t);
    int answer = move(0,0,0,0,0,maps,search);
    return answer;
}
int main(){
    vector<vector<int>> maps ={{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    cout << solution(maps);
}