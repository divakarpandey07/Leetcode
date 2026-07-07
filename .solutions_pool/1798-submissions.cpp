class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        int maxNum = 1; 
        
        
        sort(coins.begin(), coins.end());
        
        
        
        
        for (auto& c : coins) {
            if (c > maxNum) break;
            maxNum += c;
        }
        return maxNum;
    }
};