class Solution {
public:

    bool hasCycle(int n, vector<int>& explored, vector<int>& path, map<int, vector<int>>& graph) {
        
        for(int i=0; i<graph[n].size(); i++){
            
            
            if ( path[graph[n][i]] ) return true;
            
            
            path[graph[n][i]] = true;
            
            if (hasCycle(graph[n][i], explored, path, graph)) {
                return true;
            }
            
            path[graph[n][i]] = false;
        }
        
        explored[n] = true;
        return false;
        
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        
        
        map<int, vector<int>> graph;
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
        }
        
        
        vector<int> explored(numCourses, false);
        
        
        vector<int> path(numCourses, false);
        
        for(int i=0; i<numCourses; i++){
            
            if (explored[i]) continue;
            if (hasCycle(i, explored, path, graph)) return false;
            

        }
        return true;
    }
};