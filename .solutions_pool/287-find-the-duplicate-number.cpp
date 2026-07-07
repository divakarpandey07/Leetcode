class Solution {
public:
    
    
    
    
    
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int one = n;
        int two = n;

       do{
            one = nums[one-1];
            two = nums[nums[two-1]-1];
        } while(one != two); 
        
        
        one = n;
        while(one != two){
            one = nums[one-1];
            two = nums[two-1];
        }
        
        return one;
    }
};