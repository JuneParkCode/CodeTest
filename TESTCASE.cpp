#include <string>
#include <iostream>
using namespace std;

int main(){
    string s ;
    getline(cin,s);
    for(auto &c : s){
        if(c=='[') c='{';
        else if(c==']') c='}';
    }
    cout << s;
    return 0;
}
