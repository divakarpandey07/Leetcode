class Solution {
public:
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if ( len < 2 ) return 0;
        
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        
        buy[0] = -prices[0];
        sell[0] = 0;
        
        
        buy[1] = max(buy[0], 0 - prices[1]);
        sell[1] = max(sell[0], buy[0] + prices[1]);
        
        for (int i=2; i<len; i++) {
            buy[i]  = max( buy[i - 1], sell[i - 2] - prices[i]);   
            sell[i] = max(sell[i - 1],  buy[i - 1] + prices[i]);
        }
        
        return sell[len-1];
    }
};