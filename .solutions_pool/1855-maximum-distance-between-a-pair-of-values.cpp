class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        return maxDistance2(nums1, nums2);
        return maxDistance1(nums1, nums2);
    }
    
    
    int binary_search(vector<int>& nums, int start, int target) {
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) /2;
            if(nums[mid] < target) end = mid - 1;
            else start = mid+1;
        }
        return end;
    }

    int maxDistance1(vector<int>& nums1, vector<int>& nums2) {
        int mDist=0;
        int right = nums2.size() - 1;
        for(int i=0; i<nums1.size(); i++) {
            int j = binary_search(nums2, i, nums1[i]);
            mDist = max(mDist, j-i);
        }
        return mDist;
    }
    
    int maxDistance2(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0, dist = 0;
        while (i < nums1.size() && j < nums2.size() ){
            if ( nums1[i] > nums2[j] ) i++;
            else dist = max(dist, j++ - i);
        }
        return dist;
    }
};