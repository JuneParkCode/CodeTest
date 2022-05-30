#include <iostream>
#include <queue>

#define _N_MAX_ 8
#define MAX_IS(a, b) a < b ? b : a
#define DEPTH 3

using namespace std;

int arr[_N_MAX_][_N_MAX_];
int resultArr[_N_MAX_][_N_MAX_];
int visit[_N_MAX_][_N_MAX_];
int testArr[_N_MAX_][_N_MAX_];
int N, M;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

// 안전영역 계산
int getSafeZone()
{
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            count += (testArr[i][j] == 0);
        }
    }
    return (count);
}

void moveVirus(int row, int col)
{
    if (row < 0 || col < 0 || row >= N ||col >= M)
        return ;
    if (visit[row][col] || testArr[row][col] == 1)
        return ;
    visit[row][col] = 1;
    testArr[row][col] = 2;
    for (int i = 0; i < 4; ++i)
    {
        moveVirus(row + dy[i], col + dx[i]);
    }
}

// virus 퍼트리기
void pendemic()
{
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            if (visit[row][col] == 0 && resultArr[row][col] == 2)
                moveVirus(row, col);
        }
    }
}

int getResult(int &max)
{
    int res;
    memcpy(testArr, resultArr, sizeof(resultArr));
    memset(visit, 0, sizeof(visit));
    pendemic();
    res = getSafeZone();
    max = MAX_IS(res, max);
    return (max);
}

void f(int row, int col, int &max, int depth)
{
    if (row < 0 || col < 0 || row >= N || col >= M)
        return ;
    if (depth == DEPTH)
    {
        getResult(max);
        return ;
    }
    for (int r = row; r < N; ++r)
    {
        for (int c = 0; c < M; ++c)
        {
            if (r == row && c < col)
                continue;
            if (resultArr[r][c])
                continue;
            resultArr[r][c] = 1;
            f(r, c, max, depth + 1);
            resultArr[r][c] = 0;
        }
    }
}

int solver()
{
    int res;
    int max = 0;
    memcpy(resultArr, arr, sizeof(resultArr));
    f(0, 0, max, 0);
    return (max);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int x;
    cin >> N >> M;
    for (int row = 0; row < N; ++row)
    {
        for (int col = 0; col < M; ++col)
        {
            cin >> x;
            arr[row][col] = x;
        }
    }
    cout << solver();
}
