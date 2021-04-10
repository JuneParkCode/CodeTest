#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int count = 0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c == ' '){
            count = 0;
            answer += c;
            continue;
        }
        count & 1 ? answer += toupper(c) : answer += tolower(c);    // count & 1 --> t == odd, f == even... ? A:B , t-->A , f -->B
        ++count;
    }
}

string solution(string s) {
    string answer = "";
    int count = 1;
    const char T = 'a' - 'A';
    for(int i=0; i<s.size(); i++){
        char c =s[i];
        if(c == ' '){
            count=1;
            answer += s[i];
            continue;
        }
        if(count%2==0){
            if('a'<=c && c<='z')
                c -= T;
        }
        else{
            if('A'<=c && c<='Z')
                c += T;
        }
        answer += c;
        count++;
    }
    return answer;
}