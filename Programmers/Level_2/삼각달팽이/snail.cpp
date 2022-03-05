#include <string>
#include <vector>
#include <iostream>

using namespace std;
/*
정수 n이 매개변수로 주어집니다. 
다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 
맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후, 
첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 
return 하도록 solution 함수를 완성해주세요.
*/
vector<int> solution(int n) 
{
    vector<int> answer;
    int count = -1;
    int direction = 0;
    int dx[] {0,1,-1};
    int dy[] {1,0,-1};
    int x=0,y=0;
    vector<int> temp(n);
    vector<vector<int>> vec(n+1,temp);
    for(int i=n; i>0; --i)
    {
        int dir = direction%3;
        for(int j=0; j<i; ++j)
        {
            vec[y][x] = ++count;
            x += dx[dir];
            y += dy[dir];
        }
        ++direction;
    }
    for(int i=0; i<=n; ++i)
    {
        if(i==0) continue;
        for(int j=0; j<n;++j)
        {
            answer.push_back(vec[i][j]);
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    answer.push_back(++count);
    return answer;
}