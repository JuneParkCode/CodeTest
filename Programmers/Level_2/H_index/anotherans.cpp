
#include <vector>
#include <algorithm>

using namespace std;
    /*
    오름 차순으로 정렬
    벡터의 끝에서부터 조사 시작
    n번이상 인용횟수 >= n 일때 break;
    */
int solution(vector<int> citations) {
    int answer = 0;
    const int SIZE = citations.size();
    sort(citations.begin(),citations.end());
    for(int i=SIZE-1; i>=0; --i)
    {
        if(citations[i] <= answer)
        {
            break;
        }
        ++answer;
    }
    return answer;
}