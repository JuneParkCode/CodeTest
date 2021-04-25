#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board)
{
    int width = board[0].size();
    int height = board.size();
    int min = width<height?width:height;
    int answer = 0;
    if(width==1 && height==1) return 1;
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(x==0 || y==0) continue;
            if(board[y][x]){
                vector<int> v ={board[y-1][x-1],board[y][x-1],board[y-1][x]};
                board[y][x] = *min_element(v.begin(),v.end())+1;
                answer = (board[y][x] >= answer ? board[y][x] : answer);
            }   
        }
    }

    return answer*answer;
}