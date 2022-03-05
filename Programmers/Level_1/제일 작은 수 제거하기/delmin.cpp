#include <string>
#include <vector>

using namespace std;

// my ans..
// 배열 내에서 중복이 없는 case라서 가능함.
// 중복이 있는 경우에는 어떻게 해야할까?
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    auto it = arr.begin();
    int min=arr[0];
    auto n = arr.begin();
    for(int i=0; i<arr.size(); i++){
        if(min >= *n ){
            it = n;
            min = *n;
        }
        n++;
    }
    arr.erase(it);
    if(arr.empty()) arr.push_back(-1);
    return arr;
}

// 중복이 있는 경우 솔루션
// min 값을 가진 위치를 vector에 따로 저장..
vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<vector<int>::iterator> itVec;
    
    int min=arr[0];
    auto n = arr.begin();
    for(int i=0; i<arr.size(); i++){
        if(min > *n ){
            itVec.clear();
            itVec.push_back(n);
            min = *n;
        }
        else if (min == *n){
            itVec.push_back(n);
        }
        n++;
    }
    for(vector<int>::iterator it : itVec)
        arr.erase(it);
    if(arr.empty()) arr.push_back(-1);
    return arr;
}