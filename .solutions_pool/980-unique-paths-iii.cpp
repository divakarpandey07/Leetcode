class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int path = 0;
        int startX, startY;
	if (!findStartPoint( grid, startX, startY)) return 0;
        uniquePathsHelper(grid, startX, startY, path);
        return path;
    }
    
    bool findStartPoint(vector<vector<int>> &grid, int& x, int& y) {
         for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    x = i; y =j;
                    return true;
                }
            }
         }
        return false;
    }
    bool check(vector<vector<int>> &grid ) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j]  == 0 ) return false;
            }
        }
        return true;
    }
    
    
    void uniquePathsHelper(vector<vector<int>> &grid, int x, int y, int& path ) {
        
        if (x < 0 || y < 0 || x>= grid.size() || y>=grid[0].size()) return;
        
        if ( grid[x][y] < 0)  return;
 
        if ( grid[x][y] == 2) {  
            if (check(grid)) path++;
            return;
        }
        
        
        grid[x][y] = -2;
        uniquePathsHelper(grid, x, y-1, path); 
        uniquePathsHelper(grid, x, y+1, path); 
        uniquePathsHelper(grid, x+1, y, path); 
        uniquePathsHelper(grid, x-1, y, path); 
        grid[x][y] = 0;
    
    }
};