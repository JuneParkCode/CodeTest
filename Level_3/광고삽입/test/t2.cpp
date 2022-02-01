#include <iostream>

int main(){
    int i =0;
    while(1){
        for(int j = 0; j<INT32_MAX/2; i++){
            if( i == INT32_MAX ){
                i = 0;
            }
        }
    }
}