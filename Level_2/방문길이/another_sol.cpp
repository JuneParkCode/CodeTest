#include <string>
#include <set>
using namespace std;

int get_dirIdx(char dir)
{
    switch (dir)
    {
    case 'U':
        return 0;
    case 'D':
        return 1;
    case 'R':
        return 2;
    case 'L':
        return 3;   
    }
    return -1;
}
int solution(string dirs)
{
    typedef pair<int,int> point;
    typedef pair<point,point> vertex;
    set<vertex> vertexSet;
    
    point curPoint = {0,0};
    point nextPoint = curPoint;

    int dx[] ={0,0,1,-1};
    int dy[] ={1,-1,0,0};
    for(char c : dirs)
    {
        int idx = get_dirIdx(c);
        nextPoint = {curPoint.first + dx[idx],curPoint.second +dy[idx]};
        if(nextPoint.first < -5 || nextPoint.first  > 5 || nextPoint.second  > 5 || nextPoint.second < -5)
        {
            continue;
        }
        else
        {
            vertexSet.insert({curPoint,nextPoint});
            vertexSet.insert({nextPoint,curPoint});
        }
        curPoint = nextPoint;
    }
    return vertexSet.size()/2;
}