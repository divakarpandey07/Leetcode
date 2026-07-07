#ifdef CSTYLE

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int*a, int m, int n)
{
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%4d ", a[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int uniquePaths(int m, int n) {
    int* matrix = new int[m*n];
    printMatrix(matrix, m, n);
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(i==0 || j==0){
                matrix[i*n+j]=1;
            }else{
                matrix[i*n+j] = matrix[(i-1)*n+j] + matrix[i*n+j-1];
            }
        }
    } 
    printMatrix(matrix, m, n);
    int u = matrix[m*n-1];
    delete[] matrix;
    return u;
}

#else

#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector< vector <int> >  dp (n, vector<int>(m, 1));
    for (int row=1; row<n; row++) {
        for (int col=1; col<m; col++) {
            dp[row][col] = dp[row-1][col] + dp[row][col-1];
        }
    }
    return dp[n-1][m-1];
}

#endif

int main(int argc, char** argv)
{
    int m=3, n=7;
    if( argc>2){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }

    printf("uniquePaths=%d\n", uniquePaths(m,n));
    return  0;
}