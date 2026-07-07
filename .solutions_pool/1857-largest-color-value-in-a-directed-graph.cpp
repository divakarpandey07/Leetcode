const int COLOR_CNT = 26;

class Node {
public:
    Node(char c) {
        incomming = 0;
        color = c;
        processed = false;
        memset(colors, 0, sizeof(colors));
    }
    void AddMyColor() { colors[color]++; }
    void Processed() { processed = true; }
    bool isProcessed() { return processed; }
    void AddIncomming(int n=1) { incomming += n;}
    int Incomming() {return incomming;}
    void AddChildNode(int n) { children.push_back(n); }
    vector<int>& Children() { return children; }
    int ChildrenCount() { return children.size(); }
    int* Colors() {return colors;}
    int MaxColorValue() {
        int m = -1;
        for(auto c: colors) {
            m = max(m, c);
        }
        return m;
    }
    void MergeChildColors(Node& child){
        int* c = child.Colors();
        for(int i=0; i<COLOR_CNT; i++) {
            colors[i] = max(colors[i], c[i]);
        }
    }

private:
    int incomming;          
    char color;             
    bool processed;         
    int colors[COLOR_CNT];  
    vector<int> children;   
};

class Solution {
private:
    void print(vector<int>& v) {
        cout << "[";
        int i = 0;
        for(; i<v.size()-1; i++) {
            cout << v[i] << ",";
        }
        cout << v[i] << "]" << endl;
    }
private:
    int nodes_cnt;
    vector<Node> nodes;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        nodes_cnt = colors.size() ;
        for(int i=0; i<nodes_cnt; i++) {
            Node n( colors[i]-'a');
            nodes.push_back(n);
        }
        for(auto& e : edges) {
            nodes[e[0]].AddChildNode(e[1]);
            nodes[e[1]].AddIncomming();
        }
        
         vector<bool> visited(nodes_cnt, false);
        
        
        
        
        
        
        
        
        
        
        int m = -1;
        for (int i=0; i<nodes_cnt; i++) {
            
            int id = i;
            auto& n = nodes[id];
            
            
            std::fill(visited.begin(), visited.end(), false);
            
            bool succ = travel(id, visited);
            if (!succ) return -1;
           
            m = max(m, nodes[id].MaxColorValue());
        }
        return m;
    }
    
    void topologicalSort(int i, vector<int>& topSort, vector<bool>& visited) {
        if (visited[i]) return;
        visited[i] = true;
        for(auto& id : nodes[i].Children()) {
            if (!visited[id]) {
                topologicalSort(id, topSort, visited);
            }
        }
        topSort.push_back(i);
    }
    
    
    
    bool travel(int i, vector<bool>& visited ) {
        
        if (nodes[i].isProcessed()) return true;
        
        
        if (visited[i]) return false;
        visited[i] = true;
        
        
        if (nodes[i].ChildrenCount() <= 0 ) {
            nodes[i].AddMyColor();
            nodes[i].Processed();
            return true;
        }
      
        for(auto& n : nodes[i].Children() ) {
            bool succ = travel(n, visited);
            if (!succ) return false;
            nodes[i].MergeChildColors( nodes[n] );
        }
        
        nodes[i].AddMyColor();
        nodes[i].Processed();

        
        
        
        
        
        
        return true;
    }
};