#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<unsigned int>>  v (row, vector<unsigned int>(col, 0));
    unsigned int max=0;
    for (int i=0; i<obstacleGrid.size(); i++){
        for (int j=0; j<obstacleGrid[0].size(); j++){
            if(obstacleGrid[i][j] == 1){
                max = v[i][j] = 0;
            } else {
                if (i>0 && j>0) {
                    max= v[i][j] = v[i-1][j] + v[i][j-1];
                }else if(i>0){
                    max = v[i][j] = v[i-1][j];
                }else if(j>0){
                    max = v[i][j] = v[i][j-1];
                }else{
                    max = v[i][j] = 1 ;
                }
            }
        }
    }
    return max;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();

    vector< vector <unsigned int> >  dp (row, vector<unsigned int>(col, 0));

    dp[0][0] =  obstacleGrid[0][0]  ?  0 : 1;
    for (int r=1; r<row; r++) {
        dp[r][0] = obstacleGrid[r][0]  ?  0 : dp[r-1][0];
    }
    for (int c=1; c<col; c++) {
        dp[0][c] = obstacleGrid[0][c]  ?  0 : dp[0][c-1];
    }

    for (int r=1; r<row; r++) {
        for (int c=1; c<col; c++) {
            dp[r][c]  = obstacleGrid[r][c] == 1 ? 0 : dp[r][c-1] + dp[r-1][c];
        }
    }

    return dp[row-1][col-1];
}