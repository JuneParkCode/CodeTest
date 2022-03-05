#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum =0;
    string s = to_string(x);
    for(auto c:s)
        sum += c-'0';
    return x%sum==0 ? 1:0;
}