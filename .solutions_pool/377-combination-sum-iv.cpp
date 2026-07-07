class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sol[target + 1];
        sol[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            sol[i] = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j])
                    sol[i] += sol[i - nums[j]];
            }
        }
        return sol[target];
    }
};