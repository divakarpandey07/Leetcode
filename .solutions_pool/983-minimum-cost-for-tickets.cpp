class Solution {
private:
    int min(int x, int y){
        return x < y ? x : y;
    }
    int min(int x, int y, int z) {
        return min(min(x, y), z);
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        
        vector<int> dp(days.size()+1, INT_MAX);

        
        dp[0] = 0;
        dp[1] = min(costs[0], costs[1], costs[2]);

        for (int i = 2; i<= days.size(); i ++) {

            
            int m = dp[i-1] + min(costs[0], costs[1], costs[2]);

            
            
            
            
            
            

            int SevenDays = INT_MAX, ThrityDays = INT_MAX;
            for (int j=i-1; j>0; j--){
                int gaps = days[i-1] - days[j-1];
                if ( gaps < 7 )  {
                    
                    SevenDays  = dp[j-1] + min(costs[1], costs[2]);
                } else if (gaps < 30 ) {
                    
                    ThrityDays = dp[j-1] + costs[2];
                } else {
                    break;
                }
                m = min(m, SevenDays, ThrityDays);
            }
            if ( dp[i] > m )  dp[i] = m;
        }
        
        return dp[dp.size()-1];    
    }
};