class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int max=0, idx=0;
        long sum=0;
        int len = nums1.size();
        for (int i=0; i<len; i++) {
            int m = abs(nums1[i] - nums2[i]);
            if (max < m) {
                max = m; 
                idx = i;
            }
            sum += m ;
        }
        int min = max;
        for (int i=0; i<len; i++) {
            int m = abs(nums1[i] - nums2[idx]);
            if (m < min) {
                min = m;
            }
        }
        
        sum -= (max - min);
        return sum % 1000000007 ;
    }
};