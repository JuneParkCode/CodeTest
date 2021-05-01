#include <string>
#include <iostream>
using namespace std;

int main(){
    string s = "[[1,2,3,5],[5,6,7,8],[4,3,2,1]]";
    for(auto &c : s){
        if(c=='[') c='{';
        else if(c==']') c='}';
    }
    cout << s;
}