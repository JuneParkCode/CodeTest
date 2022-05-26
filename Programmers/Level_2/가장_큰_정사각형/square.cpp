#include <vector>
using namespace std;
int w, h;
bool square(int n, int x, int y, vector<vector<int>> &board)
{
    for (int dy = 0; dy < n; dy++)
    {
        for (int dx = 0; dx < n; dx++)
        {
            if (board[y + dy][x + dx] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
int solution(vector<vector<int>> board)
{
    w = board[0].size();
    h = board.size();
    int min = w < h ? w : h;
    int answer = 0;

    for (int n = min; n >= 1; n--)
    {
        for (int y = 0; y < (h - n + 1); y++)
        {
            for (int x = 0; x < (w - n + 1); x++)
            {
                if (board[y][x] == 0)
                    continue;
                bool checker = square(n, x, y, board);
                if (checker)
                {
                    x = w, y = h;
                    return n * n;
                }
            }
        }
    }

    return answer * answer;
}