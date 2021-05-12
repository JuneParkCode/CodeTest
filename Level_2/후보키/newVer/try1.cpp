#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permutation(vector<bool> &v,vector<vector<bool>> &cases, int i, const int numberOfCols)
{
    if(i>=numberOfCols)
    {
        cases.push_back(v);
        return;
    }
    v[i] = 1;
    permutation(v,cases,i+1,numberOfCols);
    v[i] = 0;
    permutation(v,cases,i+1,numberOfCols);
    return;
}
// unique case인지 검증
bool isUniqueCase(vector<bool> &v,vector<vector<string>> &relation)
{
    set<string> strSet;
    for(vector<string> row : relation)
    {
        string checkerStr = "";
        for(int idx=0; idx<v.size(); idx++)
        {
            if(v[idx])
            {
                checkerStr += to_string(idx) + row[idx];
            }
        }
        strSet.insert(checkerStr);
    }
    return strSet.size() == relation.size();
}
int solution(vector<vector<string>> relation)
{
    int numberOfCols = relation[0].size();
    /*
    * 해당 column이 포함되는지 판단하는 vector
    * 모든 조합을 생성함.
    */
    vector<bool> initVec(numberOfCols);
    vector<vector<bool>> casesVec;
    vector<vector<bool>> uniqueVec;
    permutation(initVec,casesVec,0,numberOfCols);
    // unique case들만 모아냄
    for(vector<bool> v : casesVec)
    {
        if(isUniqueCase(v,relation))
        {
            uniqueVec.push_back(v);
        }
    }
    //최소는 어떻게 구현해야하는걸까?
    //비트간 비교를 통해서 구현해야할 것 같은데 잘 모르겠다...
    //a&b를 반복해서 결과로 나타냄 0일때는 유지
    //for test
    for(auto v: uniqueVec)
    {
        for(auto n : v)
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }

    return 0;
}
int main()
{
    vector<vector<string>> s = {{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
    cout << solution(s);
}
