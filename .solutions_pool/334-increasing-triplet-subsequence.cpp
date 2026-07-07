class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool solution = false;
        if(nums.size())
        {
            int first = nums[0];
            int second = 0x7fffffff; 
            for(int i = 1; i < nums.size() && !solution; i++)
            {
                if(nums[i] > second)
                    solution = true;
                else if(nums[i] > first && nums[i] < second)
                    second = nums[i];
                else if(nums[i] < first)
                    first = nums[i];
            }
        }
        return solution;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        int first=INT_MAX, second = INT_MAX;
        
        for(int i=0; i<nums.size(); i++) {
            if ( first > nums[i] ) {
                first = nums[i];
            }else if ( first < nums[i] && nums[i] < second) {
                second = nums[i];
            }else if (nums[i] > second){
                return true;
            }
        }
        return false;
    }
};