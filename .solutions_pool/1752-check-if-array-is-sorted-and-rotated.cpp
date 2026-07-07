class Solution {
public:
    bool check(vector<int>& nums) {
        int len = nums.size();
        
        
        bool rotate = (nums[0] >= nums[len-1]);
        
        for (int i = 0; i < len-1; i++) {
            if ( nums[i] <= nums[i+1] ) continue;
            
            if (rotate) {
                rotate = false;
                continue;
            }
            return false;
            
        }
        return true;
    }
};