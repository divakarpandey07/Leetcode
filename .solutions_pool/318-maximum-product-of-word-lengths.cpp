class Solution {
public:
    
    
    
    
    
    
    
    
    

    int maxProduct(vector<string>& words) {
        
        unordered_map<int, int> maxLens;
        
        for(auto& w: words) {
            int mask = 0;
            for (auto& c: w) {
                mask = mask | ( 1 << (c-'a') );
            }
            if ( maxLens.find(mask) == maxLens.end() || maxLens[mask] < w.size() ) {
                maxLens[mask] = w.size();
            }
        }
        
        
        int result = 0;
        for (auto a : maxLens) {
            for (auto b: maxLens) {
                
                if (a.first & b.first) continue; 
                result = max( result, a.second * b.second );
            }
        }
        
        return result;
    }
};