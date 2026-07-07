class Solution {
public:
    
    bool canPartitionRecrusion(vector<int>& nums, int half, int index) {
        for (int i=index; i<nums.size(); i++){
            int h = half - nums[i];
            if ( h < 0 ) return false; 
            if ( h == 0 ) return true; 
            if ( canPartitionRecrusion(nums, h, i+1) == true ) return true;
        }
        return false;
    }

    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum +=n;
        if ( sum & 1 ) return false; 
        int half = sum / 2;
        
        
        
        std::sort(nums.begin(), nums.end(), std::greater<int>()); 

        
        return canPartitionRecrusion(nums, half, 0);
    }
};