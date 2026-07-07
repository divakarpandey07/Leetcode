class Solution {
public:
    
    bool binary_search(vector<int> &v, int target) {
        int low = 0;
        int high = v.size()-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if (target == v[mid]) return true;
            if (target < v[mid]) {
                high = mid -1;
            }else {
                low = mid + 1;
            }
        }
        
        return false;
    }
    
    
    
    bool searchMatrix01(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        for (int i=0; i<matrix.size(); i++){
            if (target < matrix[i][0] ) return false;
            if (binary_search(matrix[i], target))  return true;

        }
        return false;
    }
    
    
    
    
    bool searchMatrix02(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        int row=0,  col = matrix[0].size() - 1; 
        while (row < matrix.size() && col >=0 ) {
            if (target == matrix[row][col]) return true;
            if (target < matrix[row][col]) {
                col--;
            }else{
                row++;
            }
            
        }
        return false;
    }
    
    
    bool searchMatrix021(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        int row=0,  col = matrix[0].size() - 1; 
        while (row < matrix.size() && col >=0 ) {
            if (target == matrix[row][col]) return true;
            while ( col>=0 && target < matrix[row][col]) {
                col--;
            }
            while(col >=0 && row < matrix.size() && target > matrix[row][col]){
                row++;
            }
            
        }
        return false;
    }

    
    
    bool searchMatrix022(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size()==0) return false;
        
        int row=0,  col = matrix[0].size() - 1; 
        
        while (row < matrix.size() && col >=0 ) {
            
            if (target == matrix[row][col]) return true;
            
            if (target < matrix[row][col]) {
                int start=0, end=col;
                while(start <= end){
                    int mid = start + (end - start)/2;
                    if (target == matrix[row][mid]) return true;
                    if (target > matrix[row][mid]) {
                        start = mid + 1;
                    }else {
                        end = mid - 1;
                    }
                }
                col = end; 
            }else{
                int start=row, end=matrix.size()-1;
                while(start<=end){
                    int mid = start + (end - start)/2;
                    if (target == matrix[mid][col]) return true;
                    if (target > matrix[mid][col]) {
                        start = mid + 1;
                    }else{
                        end = mid -1;
                    }
                }
                row = start;
            }
            
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix022(matrix, target); 
        return searchMatrix021(matrix, target); 
        return searchMatrix02(matrix, target); 
        return searchMatrix01(matrix, target); 
    }
};