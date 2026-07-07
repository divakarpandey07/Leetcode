class Solution {
public:

    
    
    int findCircleNum_DFS(vector<vector<int>>& M) {
        int n = 0;
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[0].size(); j++) {
                if ( M[i][j] == 1 ) {
                    n++;
                    M[i][j] = 2;
                    mark(M, j);
                }
            }
        }
        return n;
    }

    void mark(vector<vector<int>>& M, int i ) {
        for ( int j=0;  j<M[i].size(); j++ ){
            if ( M[i][j] == 1 ) {
                M[i][j] = 2;
                mark(M, j);
            }
        }
    }

    
    
    int findCircleNum_UF(vector<vector<int>>& M) {

        vector<int> relations(M.size());
        for (int i=0; i<relations.size(); i++){
            relations[i] = i;
        }

        int n = M.size(); 
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M[0].size(); j++) {
                if ( M[i][j] == 1 && i != j ) {
                    if ( join(relations, i, j) ) n--;
                }
            }
        }
        return n;
    }

    
    
    int find(vector<int>& relations, int i ) {
        while( relations[i] != i ) {
            i = relations[i];
        }
        return i;
    }
    
    
    bool join(vector<int> &relations, int x, int y) {
        int tx = find(relations, x);
        int ty = find(relations, y);
        if ( tx != ty ) relations[tx] = ty;
        return tx != ty;
    }

    
    
    int findCircleNum(vector<vector<int>>& M) {
        return findCircleNum_UF(M);
        return findCircleNum_DFS(M);
    }
};