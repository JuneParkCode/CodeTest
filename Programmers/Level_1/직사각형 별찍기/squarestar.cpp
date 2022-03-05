#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    do{
        cin >> a >> b;
    }while(!(0<=a && a<=1000) || !(0<=b &&b<=1000));
    for(int i=0; i<b; i++){
        for(int j=0; j<a;j++)
            cout<<"*";
        cout <<"\n";
    }

    // more better
    string s ="*";
    string ss="";
    for(int i=0; i<a; i++)
        ss+=s;
    for(int i=0 ; i<b; i++)
        cout <<ss<<endl;
    return 0;
}