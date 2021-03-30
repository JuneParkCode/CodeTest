#include <string>
#include <vector>
#include <stack>
#include <iostream>


using namespace std;


// stack의 맨 마지막 - 그 다음이 같으면 두개 삭제

int check(stack<int> &container, int target){
    if(!container.empty() && container.top() == target){
        container.pop();
        return 2;
    }
    else{
        container.push(target);
        return 0;
    }
}

// BOARD
// n번째 줄의 인형
// board[col][row]
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> container;
    for(int move : moves){  //column 순서로 조사
        auto it = board.begin();
        int i=0;
        int pos = move -1 ;
        while(it!=board.end()){
            int target = board[i][pos];
            if(target){
                board[i][pos] = 0;
                answer += check(container,target);
                break;
            }''
            i++,it++;
        }
    }
    return answer;
}