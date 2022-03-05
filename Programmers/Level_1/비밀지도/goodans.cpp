#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<bool> mask(n,false);

    for(int i=0; i<n; i++){
        int r =(arr1[i]|arr2[i]);
        string s;
        while(r>1){
            s += r&1 ? "#" : " ";
            r/=2;
        }
        s += r&1 ? "#" : " ";
        answer.push_back(s);
    }
    
    return answer;
}