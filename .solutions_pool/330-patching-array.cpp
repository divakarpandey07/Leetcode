class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        return minPatches_02(nums, n);
        return minPatches_01(nums, n);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int minPatches_01(vector<int>& nums, int n) {
        long covered = 0; 
        int patch_cnt = 0;
        int i = 0;
        while (i<nums.size() ){
            
            int try_patch = covered + 1;
            
            
            if ( try_patch >= nums[i])  {
                covered += nums[i];  
                i++;
            } else { 
                patch_cnt++;
                
                covered = covered + try_patch;
            } 
            
            if (covered >=n) break;
        }
        
        
        
        while (covered < n) {
            int try_patch = covered + 1;
            patch_cnt++;
            
            covered = covered + try_patch;
        }
        return patch_cnt;
    }
    
    
    
    int minPatches_02(vector<int>& nums, int n) {
        long covered = 0;
        int patch_cnt = 0;
        int i = 0;
        while ( covered < n){
            if (i<nums.size() && nums[i] <= covered + 1) {
                covered += nums[i++];
            }else{
                
                covered = 2 * covered + 1;
                patch_cnt++;
            }
        }
        return patch_cnt;
    }
};