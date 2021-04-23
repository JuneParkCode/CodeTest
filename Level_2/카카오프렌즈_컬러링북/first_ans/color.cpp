#include <vector>
#include <algorithm>

using namespace std;

void dp(int x, int y,int prev_color,int width,int height,vector<int> &dx,vector<int> &dy,vector<int> &areaSize,vector<vector<int>> &picture,vector< vector<bool>> &searchedPixel){
    if(x>=width || y>=height ||x<0 || y<0){
        return;
    }
    for(int i=0;i<3;i++){
        int _x = x+dx[i];
        int _y = y+dy[i];
        if(_x <0 || _y <0 || _x>=width || _y >= height) continue;
        else if(prev_color == picture[y][x]){ // 이어져있음.
            if(searchedPixel[y][x]) return;
            ++areaSize.back();
            searchedPixel[y][x] = true;
        }
        else
            return;
        for(int i=0;i<4;i++){
            int _x = x+dx[i],_y = y+dy[i];
            if(_x>=width || _y>=height ||_x<0 || _y<0|| searchedPixel[_y][_x]) continue;
            dp(_x,_y,prev_color,width,height,dx,dy,areaSize,picture,searchedPixel);
        }
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<int>> newPic = picture;
    int width=n,height=m;
    vector<int> areaSize;
    vector<int> dx ={ 1,0,0,-1};
    vector<int> dy = {0,-1,1,0};
    vector<int> answer(2,0);
    vector< vector<bool> > searchedPixel = vector<vector<bool>>(height,vector<bool>(width,0));
    for(int y=0; y<height; y++){
        for(int x=0; x<width; x++){
            if(searchedPixel[y][x]) continue;
            else if(newPic[y][x]==0) searchedPixel[y][x] = true;
            else{
                areaSize.push_back(0);
                dp(x,y,newPic[y][x],width,height,dx,dy,areaSize,newPic,searchedPixel);
            }
        }
    }
    answer[0] = areaSize.size();
    answer[1] = answer[0]==0 ? 0: *max_element(areaSize.begin(),areaSize.end());
    return answer;
}