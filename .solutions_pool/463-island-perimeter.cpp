class Solution {
public:
    int edge(vector<vector<int>> &grid, int x, int y) {
        int edge = 0;
        
        if (x==0 || (x>0 && grid[x-1][y] == 0 ) ) edge++; 
        if (y==0 || (y>0 && grid[x][y-1] == 0 ) ) edge++; 
        if (x == grid.size() - 1 || 
            (x < grid.size() - 1 && grid[x+1][y] == 0)) edge++; 
        if (y == grid[0].size() - 1 || 
            (y < grid[0].size() - 1 && grid[x][y+1] == 0)) edge++; 
        
        return edge;
    }
            
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    perimeter += edge (grid, i, j);
                }
            }
        }
        return perimeter;
    }
};