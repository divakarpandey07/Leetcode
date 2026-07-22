class Solution {
private:
 static const int MAX_V = 200005; 
 int parent[MAX_V]; 
 int find_set(int v) { 
 if (v == parent[v]) 
 return v; 
 return parent[v] = find_set(parent[v]); 
 } 
 inline void union_sets(int a, int b) { 
 a = find_set(a); 
 b = find_set(b); 
 if (a != b) 
 parent[b] = a; 
 } 
public: 
 bool validPath(int n, vector<vector<int>>& edges, int source, int destination) { 
 if (source == destination) 
 return true; 
 for (int i = 0; i < n; ++i) 
 parent[i] = i; 
 for (const auto& edge : edges) { 
 union_sets(edge[0], edge[1]); 
  
 if (find_set(source) == find_set(destination)) 
 return true; 
 } 
 return find_set(source) == find_set(destination); 
 } 
}; 