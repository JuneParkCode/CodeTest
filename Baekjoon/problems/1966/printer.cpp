#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define _N_MAX_ 100

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int N;
    int M;
    int NUMBER_OF_TEST_CASE;

    cin >> NUMBER_OF_TEST_CASE;
    for (int i = 0; i < NUMBER_OF_TEST_CASE; ++i)
    {
        cin >> N;
        cin >> M;

        int x;
        int priorityMax = 0;
        queue<pair<int, int> > q;
        map<int, int> priorityMap;
        for (int j = 0; j < N; ++j)
        {
            cin >> x;
            pair<int, int> p (j, x);
            q.push(p);
            priorityMax = priorityMax < x ? x : priorityMax;
            priorityMap[x] += 1;
        }
        int n = 1;
        while (1)
        {
            pair<int, int> p = q.front();
            q.pop();
            int priority = p.second;
            if (priority < priorityMax)
            {
                q.push(p);
            }
            else
            {
                if (p.first == M)
                {
                    cout << n << endl;
                    break ;
                }
                priorityMap[priority] -= 1;
                if (priorityMap[priority] == 0)
                {
                    for (int k = 9; k >= 1; --k)
                    {
                        if (priorityMap[k])
                        {
                            priorityMax = k;
                            break ;
                        }
                    }
                }
                ++n;
            }
        }
    }
}