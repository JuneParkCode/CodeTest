#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
static vector<vector<bool>> searchedPixel;
static vector<int> areaSize;
static vector<int> dx;
static vector<int> dy;
static int w, h, global_counts;
void dp(int x, int y, int prev_color, int vIdx, vector<vector<int>> &picture)
{
    if (x >= w || y >= h || x < 0 || y < 0 || searchedPixel[y][x])
    {
        return;
    }
    if (prev_color == picture[y][x] && prev_color != 0)
    { // 이어져있음.
        areaSize[vIdx]++;
        searchedPixel[y][x] = true;
        cout << vIdx << "  |  size : " << areaSize[vIdx] << " : " << x << " " << y << endl;
    }
    else
    { // 현재 픽셀과는 이어지지 않음.
        if (picture[y][x] == 0)
        {
            prev_color = 0;
            searchedPixel[y][x] = true;
        }
        else
        {
            searchedPixel[y][x] = true;
            bool checker = 1;
            for (int i = 0; i < 4; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= w || ty >= h)
                    continue;
                if (picture[ty][tx] == picture[y][x] && searchedPixel[ty][tx])
                {
                    checker = 0;
                    searchedPixel[y][x] = false;
                    break;
                }
            }
            if (checker)
            {
                areaSize.push_back(1);
                cout << picture[y][x] << " NEW COLOR : " << x << " " << y << endl;
                if (areaSize.size() != 1)
                    vIdx++;
                prev_color = picture[y][x];
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];
        if (_x < 0 || _y < 0 || _x >= w || _y >= h)
            continue;
        dp(_x, _y, prev_color, vIdx, picture);
    }

    return;
}
