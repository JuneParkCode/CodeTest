#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto n : arr) answer+=n;
    return answer /= arr.size();
    // return answer = accumlate(arr.begin(),arr.end())/arr.size();
}
