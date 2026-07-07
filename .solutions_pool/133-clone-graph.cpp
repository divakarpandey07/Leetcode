class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        
        
        map<UndirectedGraphNode*, UndirectedGraphNode*> cloneMap;
        
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        
        UndirectedGraphNode* cloneNode = new UndirectedGraphNode(node->label);
        cloneMap[node] = cloneNode;
        
        
        while(!q.empty()){
            UndirectedGraphNode* n = q.front();
            q.pop();
            
            for(int i=0; i<n->neighbors.size(); i++){
                UndirectedGraphNode* neighbor= n->neighbors[i];
                
                if (cloneMap.find(neighbor)==cloneMap.end()){
                    
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    cloneMap[n]->neighbors.push_back(newNode);
                    cloneMap[neighbor] = newNode;
                    
                    
                    q.push(neighbor);
                }else{
                    cloneMap[n]->neighbors.push_back(cloneMap[neighbor]);
                }
            }
        }
        
        return cloneNode;
    }
};