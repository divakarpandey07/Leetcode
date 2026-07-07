class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        vector<bool> on(n, false);
        int left = 0; 
        int result = 0;
        for(int i=0; i<light.size(); i++){
            on[light[i]-1] = true;
            while (left < n && on[left]) left++;
            
            
            if (left == i+1) result++; 
        }
        return result;
    }
};