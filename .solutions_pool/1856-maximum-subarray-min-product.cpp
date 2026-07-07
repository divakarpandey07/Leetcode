class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        nums.push_back(0); 
        
        
        vector<long> sums(nums.size(), 0);
        
        
        for(int i=0; i<nums.size()-1; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
        
        stack<int> s;
        long m = 0;
        for(int i=0; i<nums.size(); i++) {
            while( !s.empty() && nums[s.top()] > nums[i]) {
                int min = nums[s.top()]; s.pop();
                int start = s.empty() ? 0 : s.top() + 1;
                int end = i;
                m = max(m , min * (sums[end] - sums[start]));
                
                
                
                
                
                
                
                
            }
            
            s.push(i);
        }
        
        return m % 1000000007;
        
    }
};