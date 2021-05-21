#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> solution(vector<string> strings) 
{
    vector<string> answer;
    const string T1  = "110";
    const string T2  = "111";
    int idxT1,idxT2;
    for(string s : strings)
    {
        // 110과 111의 자리를 바꿈
        // 앞에있는거는 110 이 111 자리에 들어가고 밀림
        // 뒤에 있는 것도 111 앞에 또는 0 뒤에 들어가고 밀림.
        string res = "";
        idxT1 = s.find(T1);
        idxT2 = s.find(T2);
        while(idxT1 != -1 || idxT2 != -1)
        {
            string newS = "";
            // 110이 제거된 string
            string front = s.substr(0,idxT1);
            string back = s.substr(idxT1+T1.length());
            // 110을 111 자리에 삽입
            newS = newS.substr(0,idxT2) + T1 + newS.substr(idxT2);
            // 다음 루프를 위한 계산.
            idxT2 = s.find(T2);
            idxT1 = s.find(T1,idxT2);
            cout << s <<endl;
        }
        answer.push_back(s);
    }
    return answer;
}
