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
21.05.01 TRY #2
SOLVED
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
int maxE(int res[]){
    int max=0;
    for(int i=0;i<4;i++){
        if(max<res[i])max=res[i];
    }
    return max;
}

/*
연속된 열이 있는 경우 --> Cur 0 + Next 1 or Cur 1 + Next 0 case로 분기함.
각 선택에 대해서 Best Answer는 모두 정해져있음
따라서 미리 계산된 수에 대해서는 저장을 해두는 것이 맞음.
*/
int dfs(int row, int curCol,int curNum,vector<vector<int>> &land,vector<vector<int>> &DPVEC){
    /*
    if(DPVEC[ROW][COL]) --> 해당 값을 반환
    else : DPVEC[ROW][COL]에 해당하는 값을 저장 후 반환함
    다양한 경우에 대해서 분기가 필요함.
    기본 알고리즘
    -- 선택한 열 --> 다음 행에서 가장 큰 수 --> 같은 열? -->Y --> SELECT //  N --> 그 다음으로 큰 수 SELECT
    */
    // Boundary conditions
    if(row+1 == land.size()) return curNum;
    if(DPVEC[row][curCol]) return DPVEC[row][curCol]; 
    // Basic algorithm
    vector<int> &nextVec = land[row+1];
    vector<int> sortedIdxVector = sortIdx(nextVec);
    int selectedIdx;
    int res[4] {0};
    if(row == 0){
        vector<int> &curVec = land[row];
        vector<int> cursortedIdxVector = sortIdx(curVec);
        int curIdx;
        for(int i=0; i<curVec.size(); i++){
            curIdx = cursortedIdxVector[i];
            curNum = curVec[curIdx];
            selectedIdx = curIdx == sortedIdxVector[0] ? sortedIdxVector[1] :sortedIdxVector[0];
            res[i] =DPVEC[row][curIdx] = curNum + dfs(row+1,selectedIdx,nextVec[selectedIdx],land,DPVEC);
        }
        return maxE(res);
    }
    for(int i=0; i<3; i++){
        if(curCol == sortedIdxVector[i]) continue;
        selectedIdx = sortedIdxVector[i];
        res[i]= curNum + dfs(row+1,selectedIdx,nextVec[selectedIdx],land,DPVEC);
    }
    return DPVEC[row][curCol] = maxE(res);
}
int solution(vector<vector<int>> land){
    // DP VEC : 미리 계산된 케이스를 저장하는 수.
    vector<vector<int>> DPVEC(land.size(),vector<int>(4,0));
    return dfs(0,0,0,land,DPVEC);    
}
int main(){
    vector<vector<int>> land ={{1,2,3,5},{5,6,7,8},{4,3,2,1}};
    cout<<solution(land);
}