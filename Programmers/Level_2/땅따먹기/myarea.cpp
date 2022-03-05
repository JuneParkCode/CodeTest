#include <vector>
#include <iostream>
using namespace std;
/*
----------------------------------
    효율성 테스트가 있는 문제
    연속적으로 같은 열을 조사 못함
    가장 큰 점수를 얻는 결과를 반환
    COL = 4 , ROW <=100,000
----------------------------------
21.04.30 풀이 실패
*/


/*
행마다 큰 순서대로...
vector<int> order(4,0) = {max_idx,..,min_idx};
*/

vector<int> sortIdx(vector<int> row){
    vector<int> order(4,0);
    // IDX 우선 저장
    for(int i=0; i<row.size(); i++){
        order[i] = i;
    }
    //SORT
    for(int i=0; i<row.size(); i++){
        for(int j=i; j<row.size(); j++){
            if(row[order[i]] < row[order[j]]){
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
    return order;
}

int dfs(int row, int prevCol,int prevNum,vector<vector<int>> &land,vector<vector<int>> &vec){
    if(row==land.size()) return prevNum;
    vector<int> &curRow = land[row];
    vector<int> sortedRowIdx = sortIdx(curRow);

    // 1st order
    int res1 = prevNum + dfs(row+1,sortedRowIdx[0],curRow[sortedRowIdx[0]],land,vec);
    if(prevCol == sortedRowIdx[1]) return res1;
    // 2nd order
    int res2 = prevNum + dfs(row+1,sortedRowIdx[1],curRow[sortedRowIdx[1]],land,vec);
    if(prevCol == sortedRowIdx[0]) return res2;

    return res1>res2 ? res1:res2;
}

// DP를 이용해서 풀어야하는 것 같은데 잘 모르겟다...
int solution(vector<vector<int>> land){
    vector<vector<int>> vec(land.size(),vector<int>(2,0));
    return dfs(0,-1,0,land,vec);    
}
int main(){
    vector<vector<int>> land ={{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    cout<<solution(land);
}