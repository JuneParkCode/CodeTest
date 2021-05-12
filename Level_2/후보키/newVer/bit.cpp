#include <iostream>
#include <vector>
#include <set>
using namespace std;

void permutation(unsigned int bit,vector<unsigned int> &cases, int i, const int numberOfCols)
{
    if(i>=numberOfCols)
    {
        cases.push_back(bit);
        return;
    }
    unsigned int bit_;
    bit_= (bit << 1) +1;
    permutation(bit_,cases,i+1,numberOfCols);
    bit_ = bit<<1;
    permutation(bit_,cases,i+1,numberOfCols);
    return;
}
// unique case인지 검증
bool isUniqueCase(unsigned int bit,vector<vector<string>> &relation)
{
    set<string> strSet;
    for(vector<string> row : relation)
    {
        unsigned bit_ = bit;
        string checkerStr = "";
        for(int idx=0; idx<relation[0].size(); idx++)
        {
            if(bit_%2==1)
            {
                checkerStr += to_string(idx) + row[idx];
            }
            bit_ = bit_ >> 1;
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
    unsigned int bit = 0;
    vector<unsigned int> casesVec;
    vector<unsigned int> uniqueVec;
    permutation(bit,casesVec,0,numberOfCols);

    // unique case들만 모아냄
    for(unsigned int bit : casesVec)
    {
        if(isUniqueCase(bit,relation))
        {
            uniqueVec.push_back(bit);
        }
    }
    //최소는 어떻게 구현해야하는걸까?
    //비트간 비교를 통해서 구현해야할 것 같은데 잘 모르겠다...
    int answer = 0;
    vector<unsigned int> testVec;
    for(int idxA = 0; idxA < uniqueVec.size(); idxA++)
    {
        bool bChecker = 0;
        for(int idxB = 0; idxB < uniqueVec.size(); idxB++)
        {
            unsigned int checkBit = uniqueVec[idxA]&uniqueVec[idxB];
            if(checkBit == uniqueVec[idxA])
            {
                bChecker =1;
            }
            else if(uniqueVec[idxB] == checkBit)
            {
                bChecker = 0;
                break;
            }
        }
        answer += bChecker;
    }

    return answer;
}
int main()
{
    vector<vector<string>> s = {{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}};
    cout << solution(s);
}
