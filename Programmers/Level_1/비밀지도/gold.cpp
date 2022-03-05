#include <string>
#include <vector>

using namespace std;
vector<bool> decode(int n){
    vector<bool> d(n,false);
    for(int i=n-1; i>=0; i--){
        if(n>=2)
            d[i] = n%2;
        else
            d[i] = n;
        n/=2;
    }
    return d;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<bool>> decodedMap1,decodedMap2,answerMap;
    //decode
    for(auto n: arr1)
        decodedMap1.push_back(decode(n));
    for(auto n: arr2)
        decodedMap2.push_back(decode(n));
    //solve
    for(int i=0; i<n; i++){
        vector<bool> v;
        for(int j=0; j<n; j++)
            v.push_back(decodedMap1[i][j] || decodedMap2[i][j]);
        answerMap.push_back(v);
    }
    for(int i=0; i<n; i++){
        string s = "";
        for(int j=0 ; j<n; j++){
            s += answerMap[i][j] ? "#" : " ";
        }
        answer.push_back(s);
    }
    
    return answer;
}