class Solution {
public:
    bool canCross_recursion(vector<int>& stones, int curr, int last_jump) {
        for(int i=curr+1; i<stones.size(); i++){
            int next_jump = stones[i] - stones[curr];
            
            if (next_jump < last_jump - 1) continue;
            
            if (next_jump > last_jump + 1) return false;
            
            if (i == stones.size() - 1 || canCross_recursion(stones, i, next_jump)) return true;
        }
        return false;
    }
    
    bool canCross_recursion_with_cache(vector<int>& stones, int curr, int last_jump, 
                                        unordered_map<int, unordered_map<int, bool>>& cache) 
    {
        
        if (cache.find(curr) != cache.end() && cache[curr].find(last_jump)!=cache[curr].end()) {
            return cache[curr][last_jump];
        }
        
        for(int i=curr+1; i<stones.size(); i++){
            int next_jump = stones[i] - stones[curr];
            if (next_jump < last_jump - 1) continue;
            if (next_jump > last_jump + 1) break;
            if (i == stones.size() - 1 || canCross_recursion_with_cache(stones, i, next_jump, cache)) {
                cache[curr][last_jump] = true;
                return true;
            }
        }
        cache[curr][last_jump] = false;
        return false;
    }
    
    bool canCross_non_recursion(vector<int>& stones) {
        
        
        unordered_map<int, unordered_set<int>> jumps = {{0, {0}}};
        
        for(int i=0; i<stones.size(); i++) {
            if (jumps.find(i) == jumps.end()){ 
                continue;
            }
            
            for(int last_jump : jumps[i]) {
                
                for (int j=i+1; j < stones.size(); j++) {
                    
                    if (stones[i] + last_jump + 1 < stones[j]) break;
                    
                    
                    for (int next_jump  = last_jump - 1;   next_jump <= last_jump + 1;  next_jump++)  {
                        if ( stones[i] + next_jump  == stones[j] ) {
                            jumps[j].insert(next_jump);
                        }
                    }
                        
                }
            }
        }
        
        return jumps.find(stones.size()-1)!=jumps.end();
    }
    
    bool canCross(vector<int>& stones) {
        
        
        return canCross_non_recursion(stones);
        
        
        unordered_map<int, unordered_map<int, bool>> cache;
        return canCross_recursion_with_cache(stones, 0, 0, cache);
        
        
        return canCross_recursion(stones, 0, 0); 
        
    }
};