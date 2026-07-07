class Solution {
private:
    vector<int> nums;    
public:
    Solution(vector<int> nums) {
        srand(time(0));
        this->nums = nums;
    }
    
    int pick(int target) {
	
        
        
        while(true) {
            int idx = rand() % nums.size();
            if ( target == nums[idx] ) {
                return idx;
            }
        }
    }
};