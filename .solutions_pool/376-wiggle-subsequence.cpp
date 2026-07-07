class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int solution = 0;
        if(nums.size())
        {
            solution = 1;
            int bigger = 0;
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] == nums[i - 1])
                    continue;
                else if(nums[i] > nums[i - 1])
                {
                    if(bigger == 0 || bigger == 2)
                    {
                        bigger = 1;
                        solution++;
                    }
                }
                else 
                {
                    if(bigger == 0 || bigger == 1)
                    {
                        bigger = 2;
                        solution++;
                    }
                }
            }
        }
        return solution;
    }
};