#include <string>
#include <vector>

using namespace std;
/*
조사하는 수 보다 뒤에 위치한 수 중에서
조사하는 수 보다 더 큰 숫자의 개수가 뺄 수 있는 수의 갯수보다 클 경우
해당 수는 제외
*/
string solution(string number, int k) {
    string answer = "";
    const int SIZE = number.length();
    for(int i=0; i<SIZE; ++i)
    {
        if(k == 0)
        {
            answer += number[i];
            return answer;
        }
        else
        {   // 뒤에 위치한 숫자 조사.
            bool checker = 0;
            for(int j=1; j<k; ++j)
            {
                if(number[i+j] >number[i] || i+j>=SIZE)
                {
                    checker=1;
                    break;
                }
            }
            if(checker)
            {
                answer+=number[i];
            }
            else
            {
                --k;
            }
        }
    }
    // 0인 경우
    if(answer == "")
        answer = "0";
    return answer;
}