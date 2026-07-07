class Solution {
public:
    
    
    
    
    
    int splitArray(vector<int>& nums, int m) {
        int min = 0, max = 0;
        for (int n : nums) {
            min = std::max(min, n);
            max += n;
        }
        while (min < max) {
            int mid = min + (max - min) / 2;
            if (hasSmallerSum(nums, m, mid)) max = mid;
            else min = mid + 1;
        }
        return min;
    }
    
    
    
    
    
    
    
    
    bool hasSmallerSum(vector<int>& nums, int m, int sum) {
        int cnt = 1, curSum = 0;
        for (int n : nums) {
            curSum += n;
            if (curSum > sum) {
                curSum = n;
                cnt++;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};