class Solution {
    void printVector(vector<int>& v) {
        cout << "[";
        for (int i = 0; i< v.size() -1 ; i ++) {
            cout << v[i] << ", ";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        
        vector<unordered_map<int, int>> graph(n);
        for(auto e : edges) {
            int x = e[0]-1;
            int y = e[1]-1;
            int d = e[2];
            graph[x][y] = graph[y][x] = d; 
        }
        
        
        
        
        vector<int> distance(n, INT_MAX);
        distance[n-1] = 0;
        
        auto cmp = [&](const int& lhs, const int& rhs) {return distance[lhs] > distance[rhs]; };
        priority_queue<int, vector<int>, decltype(cmp)> nodes(cmp);
        
        nodes.push(n-1);
        
        while( !nodes.empty() ) {
            int x = nodes.top(); nodes.pop();
            for(const auto & [ y, d ] : graph[x]) {  
                if ( distance[y] > d + distance[x] ) {
                    distance[y] = d + distance[x];
                    
                    
                    nodes.push(y); 
                }
            }
        }
        
        
        

        
        vector<bool> visited(n, false);
        vector<long> restriced_path(n, 0);
        
        nodes.push(n-1);
        restriced_path[n-1] = 1;
        visited[n-1] = true;
        
        while( !nodes.empty() ) {
            int x = nodes.top(); nodes.pop();

            
            for(const auto & [ y, d ] : graph[x]) { 
                
                if ( distance[y] > distance[x]) {
                    restriced_path[y] += restriced_path[x];
                    restriced_path[y] %= 1000000007;
                }
                if (!visited[y]) {
                    
                    nodes.push(y);
                    visited[y] = true;
                }
            }
  
            
            
        }
        
        
        return restriced_path[0];
    }
};