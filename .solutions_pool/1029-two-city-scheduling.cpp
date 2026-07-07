class Solution {
private:
    static int diff(vector<int>& x) {
        return x[1] - x[0];
    }
    static bool cmpfunc(vector<int>& lhs, vector<int>& rhs) {
        return diff(lhs) > diff(rhs);
    }

public:
    
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmpfunc);
        int result = 0;
        int len = costs.size();
        for (int i=0; i<len/2; i++) {
            result += (costs[i][0] + costs[len-i-1][1]);
        }
        return result;
    }
};