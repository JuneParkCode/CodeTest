using namespace std;

int solution(int num) {
    int n = 0;
    long temp=num;              // int 쓰면 오버플로남...
    while(temp!=1){
        temp = temp & 1 ? temp*3+1 : temp/2;
        if(++n>=500)
            return -1;
    }
    return n;
}