#include <string>

using namespace std;
void step_4(string &id){    // 처음에는 front가 아닌 iterator를 통해서 접근했음. 그러나 이 방식이 조금 더 명확해보임.
    if(id.front() == '.')
        id.erase(id.begin());
    if(id.back() == '.')
        id.pop_back();
}
void step_7(string &id){
    while(id.length()<=2){
        char c = id.back();
        id += c;
    }
}
bool check(string &id){
    if(id.length() <= 2 || id.back()=='.')  // size가 아닌 Length가 있음을 인지..
        return false;
    return true;
}
string solution(string id) {
    bool isDot = false;
    auto it = id.begin();
    while(it!=id.end()){    // 3n 짜리를 최대한 줄이기 위해서 case를 늘림, iterator를 통한 접근이 가장 합리적인 것 같다.
        if(*it>='a' && *it<='z'|| *it == '-' || *it == '_' || (*it >='0' && *it<='9')){ //step 3/2 허용된 문자
            ++it;
            isDot=false;
        }
        else if(*it>='A' && *it <= 'Z'){    //step1
            *it += 'a'-'A';
            isDot=false;
            ++it;
        }
        else if(*it == '.'){    //step3
            if(isDot){
                id.erase(it);
            }
            else{
                isDot=true;
                ++it;
            }
        }
        else{   // step 2
            it=id.erase(it);
        }
    }
    step_4(id);
    if(id.empty())  // step 5
        id="a";
    if(id.length()>15)   // step 6
        id = id.substr(0,15);   // substr(시작, 끝+1) 주의
    step_7(id);
    // step 4 , step 7 재검증
    while(!check(id)){
        step_4(id);
        step_7(id);
    }
    return id;
}