#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class set
{
    public:
        vector<T> s;
        set(){}
        void insert(T item)
        {
            for(int i=0; i<s.size(); ++i)
            {
                if(s[i] == item)
                {
                    return;
                }
            }
            s.push_back(item);
        }
        int size() const
        {
            return s.size();
        }
};

class Point
{
    public:
        int x;
        int y;
        Point(int _x, int _y) : x(_x), y(_y) {}
        Point() : x(0),y(0) {}
        friend bool operator != (const Point &l, const Point &r);
        friend bool operator == (const Point &l, const Point &r);
};
bool operator != (const Point &l, const Point &r)
{
    return !(l.x == r.x && l.y == r.y);
}
bool operator == (const Point &l, const Point &r)
{
    return (l.x == r.x && l.y == r.y);
}
class Road
{
    public:
        Point s_point;
        Point e_point;
        Road(Point s,Point e)
        {
            if(s.x < e.x ||(s.x == e. x && s.y < e.y))
            {
                s_point = s;
                e_point = e;
            }
            else
            {
                s_point = e;
                e_point = s;
            }
        }
        friend bool operator < (const Road &l, const Road& r);
        friend bool operator > (const Road &l, const Road& r);
        friend bool operator == (const Road &l, const Road& r);
        friend bool operator != (const Road &l, const Road& r);
};
bool operator < (Road &l, Road& r)
{
    if(l.s_point.x < r.s_point.x ||(l.s_point.x == r.s_point.x && l.s_point.y < r.s_point.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator == (const Road &l, const Road& r)
{
    return (l.s_point == r.s_point && l.e_point == r.e_point);
}
bool operator > (const Road &l, const Road& r)
{
    if(l.s_point.x > r.s_point.x ||(l.s_point.x == r.s_point.x && l.s_point.y > r.s_point.y))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool operator != (const Road &l, const Road& r)
{
    return !(r.s_point == l.s_point && r.e_point == l.e_point);
}
/*
U : 0
D : 1
R : 2
L : 3
*/
void get_input(vector<int> &dirInts,const string dirs)
{
    for(char c : dirs)
    {
        switch (c)
        {
        case 'U':
            dirInts.push_back(0);
            break;
        case 'D':
            dirInts.push_back(1);
            break;
        case 'R':
            dirInts.push_back(2);
            break;
        case 'L':
            dirInts.push_back(3);
            break;
        }
    }
}

int solution(string dirs)
{
    int answer = 0;
    Point curPoint(0,0);
    set<Road> visitedRoadSet;
    vector<int> dirInts;
    const int dx[] = {0,0,1,-1};
    const int dy[] = {1,-1,0,0};
    get_input(dirInts,dirs);
    for(int i=0; i<dirInts.size(); ++i)
    {
        Point nextPoint(curPoint.x+dx[dirInts[i]],curPoint.y+dy[dirInts[i]]);
        if(nextPoint.x < -5 || nextPoint.x >5 || nextPoint.y <-5 || nextPoint.y >5)
        {
            continue;
        }
        visitedRoadSet.insert(Road(curPoint,nextPoint));
        curPoint = nextPoint;
    }
    
    return visitedRoadSet.size();
}