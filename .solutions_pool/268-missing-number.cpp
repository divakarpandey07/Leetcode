class Solution {
public:
    
    
    
    
    
    int missingNumber01(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result ^=  nums[i];
        }
        for(int i=1; i<=nums.size(); i++){
            result ^=(i);
        }
        return result;
    }
    
    
    int missingNumber02(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<nums.size(); i++){
            result = result ^ (i+1) ^ nums[i];
        }
        return result;
    }
    
    int missingNumber(vector<int>& nums) {
        
        return missingNumber02(nums); 
        return missingNumber01(nums); 
    }
};