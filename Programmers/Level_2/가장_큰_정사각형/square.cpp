#include<vector>
using namespace std;
int width,height;
bool square(int n, int x, int y,vector<vector<int>> &board){
    for(int dy=0;dy<n;dy++){
        for(int dx=0;dx<n;dx++){
            if(board[y+dy][x+dx]==0){
                return 0;
            }
        }
    }
    return 1;
}
int solution(vector<vector<int>> board)
{
    width = board[0].size();
    height = board.size();
    int min = width<height?width:height;
    int answer = 0;

    for(int n=min;n>=1;n--){
        for(int y=0; y<(height-n+1); y++){
            for(int x=0; x<(width-n+1); x++){
                if(board[y][x]==0) continue;
                bool checker = square(n,x,y,board);
                if(checker){
                    x=width,y=height;
                    return n*n;
                }
            }
        }
    }
    

    return answer*answer;
}