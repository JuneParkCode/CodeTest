
/*
other code
+- 50% fast..
테스트 1 〉	통과 (0.01ms, 3.94MB)
테스트 2 〉	통과 (0.04ms, 3.96MB)
테스트 3 〉	통과 (0.57ms, 4.04MB)
테스트 4 〉	통과 (3.93ms, 6.51MB)
테스트 5 〉	통과 (7.88ms, 9.8MB)
테스트 6 〉	통과 (0.07ms, 3.92MB)
테스트 7 〉	통과 (0.36ms, 4.05MB)
테스트 8 〉	통과 (3.82ms, 6.33MB)
테스트 9 〉	통과 (8.25ms, 9.93MB)
테스트 10 〉	통과 (3.14ms, 6.36MB)
테스트 11 〉	통과 (3.12ms, 6.62MB)
테스트 12 〉	통과 (4.65ms, 7.72MB)
테스트 13 〉	통과 (5.75ms, 8.41MB)
테스트 14 〉	통과 (0.02ms, 3.9MB)
테스트 15 〉	통과 (1.28ms, 5.23MB)
테스트 16 〉	통과 (0.65ms, 4.34MB)
테스트 17 〉	통과 (1.25ms, 5.13MB)
테스트 18 〉	통과 (0.70ms, 4.35MB)
테스트 19 〉	통과 (0.15ms, 3.96MB)
테스트 20 〉	통과 (1.04ms, 4.76MB)
테스트 21 〉	통과 (1.88ms, 6.18MB)
테스트 22 〉	통과 (2.62ms, 9.94MB)
테스트 23 〉	통과 (3.46ms, 9.6MB)
테스트 24 〉	통과 (5.05ms, 9.53MB)
테스트 25 〉	통과 (0.01ms, 3.9MB)
테스트 26 〉	통과 (0.01ms, 3.93MB)
테스트 27 〉	통과 (0.01ms, 3.95MB)
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<float, int> a, pair<float, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }

    return true;
}


vector<int> solution(int N, vector<int> stages) {

    vector < pair<float, int>> temp;
    vector<int> answer;

    sort(stages.begin(), stages.end());

    int total_cnt = 0, cnt = 0, n_cnt = 1, i = 0;
    float fail = 0;
    while (true)
    {
        if (n_cnt > N) break;

        if (i == stages.size()-1 || stages[i] != n_cnt )
        {
            if (stages[i] == n_cnt) cnt++;

            if (cnt == 0) temp.push_back(make_pair(0, n_cnt));
            else temp.push_back(make_pair(((float)(cnt) / (stages.size() - total_cnt)), n_cnt));
            total_cnt += cnt;
            cnt = 0;
            n_cnt++;
        }
        else
        {
            i++;
            cnt++;
        }
    }
    sort(temp.begin(), temp.end(), compare);

    for (int i = 0; i < temp.size(); i++)
    {
        answer.push_back(temp[i].second);
    }

    return answer;
}

