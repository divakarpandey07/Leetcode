class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        
        
        
        
        
        
        
        vector<int> lens(groups.size());
        int total_len=0;
        for(int i=groups.size()-1; i >=0; i--) {
            total_len += groups[i].size();
            lens[i] = total_len;
        }
        
        
        
        int i = 0, j = 0; 
        while ( i < groups.size() && j < nums.size() ) {
            
            if (nums.size() - j < lens[i]) return false;
            
            
            if ( nums[j] != groups[i][0]) {
                j++;
                continue;
            }
            
            
            bool match = true;
            for(int k=0; k<groups[i].size(); k++) {
                if ( nums[j+k] != groups[i][k]) {
                    match=false;
                    break;
                }
            }
            
            
            if (match) {
                j += groups[i].size();
                i++;
            }else{
                j++;  
            }
        }
        
        return i == groups.size();
    }
};