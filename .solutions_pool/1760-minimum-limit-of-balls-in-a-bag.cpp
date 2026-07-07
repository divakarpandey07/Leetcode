class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        
        int max_penalty = 0;
        long long sum = 0;
        for (auto& n: nums){
            max_penalty = max(max_penalty, n);
            sum += n;
        }
        
        
        int min_penalty = sum / (nums.size() + maxOperations);
        min_penalty = max(1, min_penalty); 
        
        
        while (min_penalty < max_penalty) {
            int mid = min_penalty + (max_penalty - min_penalty) / 2;
            
            
            int ops = 0;
            for (auto& n : nums){
                if (n <= mid) continue; 
                ops += (n-1) / mid;
            }
            
            
            
            if (ops > maxOperations) {
                min_penalty = mid + 1;
            }else{
                max_penalty = mid;
            }
        }
        return min_penalty;
        
    }
};