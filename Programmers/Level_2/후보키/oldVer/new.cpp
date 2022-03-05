#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <err.h>

using namespace std;
/*
최소성, 유일성을 갖는 튜플 조합의 갯수를 구하여라.
*/

/*
-생각
 1. 튜플의 다양한 조합을 무작위로 다 대입해야하는가?
 1-1. 그렇다면 튜플의 종류를 일일히 만드는 과정은 어떻게 할 것인가?
 1-2. 갯수를 중심으로 풀어나가야함. BFS?
*/
bool isUnique(set<int> q, vector<vector<string>> &table)
{
    // q열의 원소들만 조합
    set<string> checkSet;
    for(vector<string> element : table)
    {
        string newStr = "";
        for(int i : q)
        {
            newStr += " "+to_string(i)+"_"+element[i];
        }
        checkSet.insert(newStr);
    }
    return checkSet.size() == table.size();
}
int solution(vector<vector<string>> relation) 
{
    int answer = 0;
    vector<set<int>*> *newVec = new(vector<set<int>*>);
    vector<set<int>*> &q = *newVec;
    set<int> notuniqueSet;
    set<set<int>> uniqueSet;
    for(int i=0; i<relation[0].size(); i++)
    {
        if(!isUnique({i},relation))
        {
            notuniqueSet.insert({i});
            set<int>* newSet = new(set<int>);
            newSet->insert({i});
            q.push_back(newSet); 
        }
        else
        {
            uniqueSet.insert({i});
        }
    }


  
    for(int i=0; i<q.size(); i++)
    {
        set<int>* curSet = q[i];
        if(curSet->size() >= notuniqueSet.size()) break;
        for(int n : notuniqueSet)
        {
            set<int>* newSetP = new(set<int>);
            *newSetP = *curSet;
            if(*(--newSetP->end()) >= n) continue;
            newSetP->insert(n);
            if(!isUnique(*newSetP,relation))
            {
                q.push_back(newSetP);
            }
            else
            {
                uniqueSet.insert(*newSetP);
            }
        }
    }
   
    

    for(auto p : q)
        delete p;
    delete newVec;

    for(auto set : uniqueSet)
    {
        for(auto n : set)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    return uniqueSet.size();
}

int main()
{
    vector<vector<string>> s = {{{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"}, {"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}}};
    
    cout << solution(s);
}