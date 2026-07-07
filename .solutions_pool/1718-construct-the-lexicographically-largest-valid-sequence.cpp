class Solution {
private:
    void print(vector<int>& v) {
        cout << "[" ;
        for(int i=0; i<v.size()-1; i++){
            cout << v[i] << ",";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1, 0);
        vector<bool> available(n+1, true); 
        available[0] = false;
        
        dfs(available, result, 0, n);
        
        return result;
    }
    
    bool dfs(vector<bool>& available, vector<int>& result, int pos, int cnt){
        
        if (cnt == 0) return true;
        
        
        int n = 0;
        for(int i = available.size()-1; i > 0; i--){
            
            if (!available[i]) continue;
            
            if ( i > 1 && pos + i >= result.size()) continue;
            if ( i > 1 && (result[pos] != 0 || result[pos+i] != 0)) continue;
            
            
            available[i] = false;
            result[pos] = i;
            if (i > 1) result[pos+i] = i;
            int next_pos = pos;
            while( next_pos < result.size() && result[next_pos]!=0) next_pos++;
            
            
            if (dfs(available, result, next_pos, cnt-1)) return true; 
            
            
            available[i] = true;
            result[pos] = 0;
            if (i > 1) result[pos+i] = 0;
        }
        
        return false;
    }
};